a = 0
b = 0
c = 0
d = 0
O_pkt = 0
X_pkt = 0

board = [["X"," ","X"," ","X"," ","X"," "],
        [" ","X"," ","X"," ","X"," ","X"],
        [" "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "],
        ["O"," ","O"," ","O"," ","O"," "],
        [" ","O"," ","O"," ","O"," ","O"]]
def tablica():
    print(8*"+-------", end="")
    print("+", end="")
    print("\n", end="")
    for i in range(0,8):
        for j in range(0,8):
            print("|  ",board[i][j],"  ", end="")
        print("|", end="")
        print("\n", end="")
        print(8*"+-------", end="")
        print("+", end="")
        print("\n", end="")

def wybieranie():
    print("WYBIERANIE: ")
    print("Podaj linie: ")
    global a
    a=int(input())
    print("Podaj kolumne: ")
    global b
    b = int(input())

def wstawianie():
    print("WSTAWIANIE: ")
    print("Podaj linie: ")
    global c
    c = int(input())
    print("Podaj kolumne: ")
    global d
    d = int(input())

def czarne():
    global X_pkt
    wybieranie()

    if(a > 8 or b >8 or a<=0 or b <=0):
        print("Podano niepoprawna liczbe!")
        wybieranie()
    else:
        wstawianie()
        if(c > 8 or c >8 or c<=0 or d <=0):
            print("Podano niepoprawna liczbe!")
            wstawianie()

    if ((board[c - 1][d - 1]) == "O"):
        X_pkt += 1

    board[a-1][b-1] = " "
    board[c-1][d-1] = "X"
    tablica()
    biale()

def biale():
    global O_pkt
    wybieranie()

    if (a > 8 or b > 8 or a <= 0 or b <= 0):
        print("Podano niepoprawna liczbe!")
        wybieranie()
    else:
        wstawianie()
        if (c > 8 or c > 8 or c <= 0 or d <= 0):
            print("Podano niepoprawna liczbe!")
            wstawianie()
    if((board[c - 1][d - 1]) == "X"):
        O_pkt += 1
    board[a - 1][b - 1] = " "
    board[c - 1][d - 1] = "O"
    tablica()
    czarne()

tablica()
czarne()
