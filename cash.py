from cs50 import get_float

QUARTER, DIME, NICKEL, PENNY = 25, 10, 5, 1
coins_list = [QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1]


def main():
    change = get_change()

    print(calculate_coins(change))


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            return n


def calculate_coins(change):
    coins = int(change) * 4

    change = int((change - int(change)) * 100)

    for coin in coins_list:
        coins += change // coin
        change %= coin

    return coins


main()
