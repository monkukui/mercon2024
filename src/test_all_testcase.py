# /srcでこのコードを実行してください
import os

# 問題のフォルダ名一覧を取得
def get_problem_dirs():
    path = "."
    dir = [name for name in os.listdir(path) if (os.path.isdir(os.path.join(path, name)) and name not in ["rime", "template", "sample-A", "common"])]
    return dir

# 問題の解放名一覧を取得
def get_solution_dirs(problem_dir):
    dir = [name for name in os.listdir(problem_dir) if (os.path.isdir(os.path.join(problem_dir, name)) and name not in ["rime-out", "ss-out", "statement", "tests", ".idea"])]
    return dir

# 解放がAC解かどうか確認する
def is_solution_AC(problem_dir, solution_name):
    SOLUTION_dir = os.path.join(problem_dir, solution_name, "SOLUTION")
    is_AC = True
    with open(SOLUTION_dir, 'r') as file:
        line = file.readline()
        while line:
            is_comment = ("#" in line[:10])
            if not is_comment:
                if "challenge_cases" in line:
                    is_AC = False
            line = file.readline()
    return is_AC

# ある問題の手作りの.outのファイル名一覧を取得
def get_handmade_outs(problem_dir):
    temp_dir = os.path.join(problem_dir, "tests")
    files = [name for name in os.listdir(temp_dir) if os.path.isfile(os.path.join(temp_dir, name)) and ".out" in name]
    return files

def compare_outs(problem_dir):
    try:
        hand_out_names = get_handmade_outs(problem_dir)
        solution_names = get_solution_dirs(problem_dir)
        solution_all_good = True
        # 解放ごとに
        for solution_name in solution_names:
            is_AC = is_solution_AC(problem_dir, solution_name)
            if not is_AC:
                continue
            # 手動で作られた.outが一致するかチェックする
            for hand_out_name in hand_out_names:
                hand_out_path = os.path.join(problem_dir, "tests", hand_out_name)
                code_out_path = os.path.join(problem_dir, "rime-out", solution_name, hand_out_name)

                # TLE解とかはsample.outが生成されない場合があるためファイルが存在するときだけチェック
                if os.path.isfile(code_out_path):
                    with open(hand_out_path, 'r') as file1, open(code_out_path, 'r') as file2:
                        file1_contents = file1.read()
                        file2_contents = file2.read()

                        if file1_contents != file2_contents:
                            print(f"\033[31m [ ERROR ] \033[0m {problem_dir}/{solution_name}: {hand_out_name}の解が一致しません")
                            solution_all_good = False
                else:
                    print(f"\033[31m [ ERROR ] \033[0m {problem_dir}/{solution_name}: {hand_out_name}の解が存在しません、WAやTLEでrimeの実行が途中で止まっている可能性があります")
                    solution_all_good = False
                    break
        if solution_all_good:
            print(f"\033[32m [ PASS ] \033[0m {problem_dir}")
    except FileNotFoundError as e:
        print(f"\033[31m [ Unexpected Error ] \033[0m: {e}")

problem_dirs = get_problem_dirs()
for problem_dir in problem_dirs:
    compare_outs(problem_dir)
