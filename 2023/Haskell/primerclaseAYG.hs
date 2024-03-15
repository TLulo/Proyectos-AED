
--Ejercicio 1a
escero :: Int -> Bool

escero x= x == 0

--Ejercicio 1b
esPositivo :: Int -> Bool

esPositivo x = x > 0

--Ejercicio 1c
esVocal :: Char -> Bool

esVocal x= x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'

--Ejercicio 2a
paratodo :: [Bool] -> Bool

paratodo [] = True
paratodo (x:xs) = x && paratodo xs

--Ejercicio 2b
sumatoria :: [Int] -> Int

sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

--Ejercicio 2c
productoria :: [Int] -> Int

productoria [] = 1
productoria (x:xs) = x * productoria xs

--Ejercicio 2d
factorial :: Int -> Int

factorial 0 = 1
factorial x = productoria[1..x]

--Ejercicio 2e
promedio :: [Int] -> Int

promedio [] = 0
promedio xs = div (sumatoria xs)  (length xs)

--Ejercicio 3
pertenece :: Int -> [Int] -> Bool

pertenece x [] = False
pertenece x (y:ys) = x == y || pertenece x ys

--Ejercicio 4a

paratodo' :: [a] -> (a -> Bool) -> Bool

paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t

--Ejercicio 4b
existe' :: [a] -> (a -> Bool) -> Bool

existe' [] t = False
existe' (x:xs) t = t x || existe' xs t

--Ejercicio 4c 
sumatoria' :: [a] -> (a -> Int) -> Int

sumatoria' [] t = 0
sumatoria' (x:xs) t= t x + sumatoria' xs t

--Ejercicio 4d
productoria' :: [a] -> (a -> Int) -> Int

productoria' [] t = 1
productoria' (x:xs) t= t x * productoria' xs t

--Ejercicio 5

paratodo'' :: [Bool] -> Bool

paratodo'' xs = paratodo' xs id

--Ejercicio 6a
esPar :: Int -> Bool

esPar x = mod x 2 == 0


todosPares :: [Int] -> Bool

todosPares xs = paratodo' xs esPar

--Ejercicio 6b

hayMultiplo :: Int -> [Int] -> Bool

hayMultiplo x ys = existe' ys (multiplo x)


multiplo :: Int -> Int -> Bool

multiplo x y = mod y x == 0    

--Ejercicio 6c

sumaCuadrados :: Int -> Int

sumaCuadrados x = sumatoria' [0..x] cuadrado

cuadrado :: Int -> Int

cuadrado x = x^2

--Ejercicio 6d

factorial' :: Int -> Int

factorial' x = productoria' [1..x] id

--Ejercicio 6e

multiplicaPares :: [Int] -> Int

multiplicaPares xs = productoria' xs devuelvepar


devuelvepar :: Int -> Int

devuelvepar x
    | esPar x = x
    |otherwise = 1

{- Ejercicio 7
*¿Que hacen estas funciones?

Map: Aplica una funcion sobre cada elemento de la lista, devolviendo una nueva lista nueva con los elementos modificados (con el tipo que devuelve la funcion).

Filter: Filtra una lista con los elementos que cumplen una funcion, devolviendo una lista del mismo tipo que la de entrada y con los elementos que cumplen la funcion.
 
*¿A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1?

esta funcion sumara uno a cada elemento de la lista quedando.
[2, -3, 7, 3, -7]

*¿Y la expresion filter esPositivo [1, -4, 6, 2, -8]?

 esta funcion comprobara los elementos x > 0 y creara una lista con solo los valores que cumplan, quedando de la forma
 [1,6,2]
-}

--Ejercicio 8a
duplicax :: [Int] -> [Int]

duplicax [] = []
duplicax (x:xs) = (2*x):duplicax xs

--Ejercicio 8b
duplicax' :: [Int] -> [Int]

duplicax' xs= map (*2) xs 

--Ejercicio 9a

soloPares :: [Int] -> [Int]

soloPares [] = []
soloPares (x:xs)
    |esPar x = x:soloPares xs
    |otherwise = soloPares xs

--Ejercicio 9b

soloPares' :: [Int] -> [Int]

soloPares' xs = filter esPar xs

--Ejercicio 9c

multiplicaPares' :: [Int] -> Int

multiplicaPares' xs = productoria' (soloPares' xs) id

--Ejercicio 10a

primIgualesA ::Eq (a)=> a -> [a] -> [a]

primIgualesA x [] = []
primIgualesA x (y:ys)
    |y == x = y:primIgualesA x ys
    |otherwise = []

--Ejercicio 10b

primIgualesA' ::Eq (a) => a -> [a] -> [a]

primIgualesA' x ys = takeWhile (==x) ys

--Ejercicio 11a

primIguales :: Eq (a) => [a]->[a]

primIguales [x] = [x]
primIguales [] = []
primIguales (x:y:xs)
    |x == y = x:primIguales(y:xs)
    |otherwise = x:primIguales []

--Ejercicio 11b

primIguales' :: Eq (a) => [a] -> [a]

primIguales' [] = []
primIguales' (x:xs) = primIgualesA' x (x:xs)

--Ejercicio 12*

cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b

cuantGen op z [] t = z
cuantGen op z (x:xs) t = op (t x) (cuantGen op z xs t)  


--Para todo
paratodo''' :: [a] -> (a -> Bool) -> Bool
paratodo''' xs t = cuantGen (&&) True xs t

--Existe
existe''' :: [a] -> (a -> Bool) -> Bool
existe''' xs t = cuantGen (||) False xs t

--Sumatoria
sumatoria''' :: [a] -> (a -> Int) -> Int
sumatoria''' xs t = cuantGen (+) 0 xs t

--Productoria
productoria''' :: [a] -> (a -> Int) -> Int
productoria''' xs t = cuantGen (*) 1 xs t

{-Ejercicio 13*
aclaracion:
usare * para mostrar las subexpreciones
utilizare - para hacer comentarios sobre las variables utilizadas
separaremos las funciones por partes, primero donde se define su tipo y por otra parte cuando se define el uso.

a)Esta bien tipada:
    subexpreciones:
        f :: (a, b)
            * (a,b) = tupla de dos elementos (pueden ser de diferente tipo o del mismo).
            * a = a -> a (una variable de cualquier tipo)
            * b = b -> b (una variable de cualquier tipo)
            -(a y b pueden ser de diferente tipo pero no es obligatorio.)
        f (x , y)
            *(x,y) = tupla de dos elementos (donde x hace referencia al tipo de a),(y hace referencia al tipo de b)
            * x = x -> a (una variable del tipo de a)
            * y = y -> b (una variable del tipo de b)

b)Esta mal tipada, pues en f debe entrar una lista de tuplas y cuando se define el uso de f lo definen para una tupla

c)Esta bien tipada:
    subexpreciones:
        f :: [(a, b)]
            *[(a,b)] = Lista de tuplas.
            *(a,b) = tupla de dos elementos (pueden ser de diferente tipo o del mismo).
            * a = a -> a (una variable de cualquier tipo)
            * b = b -> b (una variable de cualquier tipo)
            -(a y b pueden ser de diferente tipo pero no es obligatorio.)
        f (x:xs)
            * (x:xs) = Lista (En este caso de tuplas)
            * x = Primer elemento de la Lista
            * xs = Lista (En este caso de tuplas)
d)Esta bien tipada:
    subexpreciones:
        f :: [(a, b)]
            *[(a,b)] = Lista de tuplas.
            *(a,b) = tupla de dos elementos (pueden ser de diferente tipo o del mismo).
            * a = a -> a (una variable de cualquier tipo)
            * b = b -> b (una variable de cualquier tipo)
            -(a y b pueden ser de diferente tipo pero no es obligatorio.)
        f ((x, y) : ((a, b) : xs))
            *((x,y):((a,b):xs)) = Lista de tuplas
            *xs = Lista (En este caso de tuplas)
            *(a,b) = tupla de dos elementos (pueden ser de diferente tipo o del mismo).
            *(x,y) = tupla de dos elementos (donde x hace referencia al tipo de a),(y hace referencia al tipo de b)
            * a = a -> a (una variable de cualquier tipo)
            * b = b -> b (una variable de cualquier tipo)
            * x = x -> a (una variable del tipo de a)
            * y = y -> b (una variable del tipo de b)
            -(a y b pueden ser de diferente tipo pero no es obligatorio.)
e)Esta bien tipada para cualquier lista de tuplas cuyo primer elemento sea 0:
    subexpreciones:
        f :: [(Int, a)]
            *[(Int,a)] = Lista de tuplas
            *(Int,a) = Tupla de dos elementos (Primer elemento es obligatoriamente un Int)
            * Int = una variable de tipo Int
            * a = a -> a (una variable de cualquier tipo)
        f [(0, a)]
            *[(0,a)] = Lista de tuplas
            *(0,a) = tupla de dos elementos (pueden ser de diferente tipo o del mismo).
            * 0 = Constante de tipo Int 
            * a = * a = a -> a (una variable de cualquier tipo)
f) Esta mal tipada, pues el orden de los elementos no debe cambiar.
g)Esta bien tipada
     f :: (Int -> Int) -> Int
        * (Int -> Int) = funcion aplicada sobre un Int que devuelve un Int
        * Int = Variable de tipo Int
    f a b
        a = una funcion de (Int -> Int)
        b = variable de tipo Int
h) Esta bien tipada para cualquier entrada de una funcion cualquiera y el numero 3
-Osea de la forma (f a 3) tipa y de la forma (f a 4) no tipa (el segundo elemento de f debe ser 3)
    f :: (Int -> Int) -> Int
        * (Int -> Int) = funcion aplicada sobre un Int que devuelve un Int
        * Int = Variable de tipo Int
    f a 3
        a = una funcion de (Int -> Int)
        3 = Constante de tipo Int
i)Esta mal tipada

-}
--Ejercicio 14a
f :: (a,b) -> b
f (a,b) = b

--Ejercicio 14b
--No es posible pues no sabemos el tipo de c

--Ejercicio 14c
f' :: (a -> b) -> a -> b
f' t a = t a

--Ejercicio 14d
f'' :: (a -> b) -> [a] -> [b]
f'' t [] = []
f'' t (x:xs) = (t x):f'' t xs

--Ejercicio 14e
f''' :: (a -> b) -> (b -> c) -> a -> c

f''' t t' x = t'(t x)