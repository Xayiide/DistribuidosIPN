import random
import string

def main():
    n = 5000000

    big = ""

    print("Creando palabras...")
    for i in range(n):
        word = ''.join(random.choice(string.ascii_uppercase) for x in range(3))
        word += " "
        big  += word

    print("Palabras creadas")
    print("Tamaño de big: " + str(len(big)))
    print("Encontrando ocurrencias de IPN...")

    num = big.count("IPN")
    print("Numero de apariciones de IPN: " + str(num))
    

if __name__ == '__main__':
    main()
