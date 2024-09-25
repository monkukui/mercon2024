// [dependencies]
// rand = { version = "=0.7.3", features = ["small_rng"] }
// rand_chacha = "=0.2.2"
// proconio = { version = "=0.3.6", features = ["derive"] }
use rand::prelude::*;

const TIMELIMIT: f64 = 2.5;

fn main() {
    let mut timer = Timer::new();
    let mut rng = rand_chacha::ChaCha20Rng::seed_from_u64(0);
    let input = read_input();
    let mut output = Output {
        a: (0..input.n).collect(),
    };
    let max_score = simulated_annealing(&input, &mut output, &mut timer, &mut rng);
    println!("{}", max_score);
}

fn simulated_annealing(
    input: &Input,
    output: &mut Output,
    timer: &mut Timer,
    rng: &mut rand_chacha::ChaCha20Rng,
) -> i64 {
    const T0: f64 = 10000.0;
    const T1: f64 = 100.0;
    let mut temp = T0;
    let mut prob;

    // let mut best_out = output.clone();
    let mut best_score = compute_score(input, output);

    let mut count = 0;
    let mut now_score = best_score;

    loop {
        if count >= 100 {
            let passed = timer.get_time() / TIMELIMIT;
            if passed >= 1.0 {
                break;
            }
            temp = T0.powf(1.0 - passed) * T1.powf(passed);
            count = 0;
        }
        count += 1;

        // 近傍解生成。
        let i = rng.gen_range(0, input.n);
        let j = rng.gen_range(0, input.n);
        if i == j {
            continue;
        }
        output.a.swap(i, j);

        let new_score = compute_score(input, &output);
        prob = f64::exp((new_score - now_score) as f64 / temp);
        if now_score < new_score || rng.gen_bool(prob) {
            now_score = new_score;
        } else {
            output.a.swap(i, j);
        }

        if best_score > now_score {
            best_score = now_score;
            // best_out = output.clone();
        }
    }
    now_score
}

fn compute_score(input: &Input, out: &Output) -> i64 {
    let mut score = 0;
    let mut amount = 0;
    for &i in out.a.iter() {
        score += input.a[i] * (1 + 2.min(amount / input.x));
        amount += input.a[i];
    }
    score
}

struct Input {
    n: usize,
    x: i64,
    a: Vec<i64>,
}

fn read_input() -> Input {
    use proconio::input;
    input! {
        n: usize,
        x: i64,
        a: [i64; n],
    }

    Input { n, x, a }
}

#[derive(Debug, Clone)]
struct Output {
    a: Vec<usize>,
}

fn get_time() -> f64 {
    let t = std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .unwrap();
    t.as_secs() as f64 + t.subsec_nanos() as f64 * 1e-9
}

struct Timer {
    start_time: f64,
}

impl Timer {
    fn new() -> Timer {
        Timer {
            start_time: get_time(),
        }
    }

    fn get_time(&self) -> f64 {
        get_time() - self.start_time
    }

    #[allow(dead_code)]
    fn reset(&mut self) {
        self.start_time = 0.0;
    }
}
