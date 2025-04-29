from cs50 import get_float



def main():
    coin_values  = [25,10,5,1]
    totalcoins = 0;
    while True:
        cash = get_float("Cash: ")
        cash = cash * 100
        if cash > 0:
            break
    while cash !=0:
        for coin in coin_values:
            value = calcoins(coin,cash)
            cash = cash - (value * coin)
            totalcoins += value
    print(totalcoins)


def calcoins(coinvalue, cash):
    coin = 0
    while cash >= coinvalue:
        cash = cash - coinvalue
        coin = coin + 1
    return coin


main()
