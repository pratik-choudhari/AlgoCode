"""This program displays the moves to solve
    Tower of Hanoi puzzle"""


def toh(n, source, aux, target):
    if n == 1:
        print(f'Move Disk 1 from {source} to {target}')
        return 1
    left_count = toh(n - 1, source, target, aux)
    print(f'Move Disk {n} from {source} to {target}')
    right_count = toh(n - 1, aux, source, target)
    return left_count + right_count + 1


if __name__ == "__main__":
    n, source, aux, target = input(
        "Number of disks and 3 towers labels: ").split()
    n = int(n)
    count = toh(n, source, aux, target)
    print(f"It took {count} moves in total")
