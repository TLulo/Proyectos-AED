--1
--a)
esCero :: Int -> Bool 
esCero x = x == 0 

--b)
esPositivo :: Int -> Bool 
esPositivo x = x > 0

--c)
esVocal :: Char -> Bool 
esVocal x = x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' 
--2)

--a)
paratodo :: [Bool] -> Bool
paratodo [] = True 
paratodo (x:xs) = (x == True) && paratodo xs 

--b)
sumatoria :: [Int] -> Int 
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs 

--c)
productoria :: [Int] -> Int
productoria [] = 1 
productoria (x:xs) = x * productoria xs 

--d)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1) 

--e) 
promedio :: [Int] -> Int
promedio [] = 0
promedio (x:xs) = div (sumatoria (x:xs)) (length (x:xs))

--3)
pertenece :: Int -> [Int] -> Bool 
pertenece _ [] = False
pertenece n (x:xs) = (n == x) || pertenece n xs   
--4)

--a)
paratodo' :: [a] -> (a -> Bool) -> Bool 
paratodo' [] f = True 
paratodo' (x:xs) f = f x && paratodo' xs f  

--b)
existe' :: [a] -> (a -> Bool) -> Bool 
existe' [] f = False 
existe' (x:xs) f = f x || existe' xs f    

--c)
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] f = 0 
sumatoria' (x:xs) f = f x + sumatoria' xs f   

--d)
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] f = 1 
productoria' (x:xs) f = f x * productoria' xs f  
 
--5)

paratodo'' :: [Bool] -> Bool
paratodo'' (x:xs)= paratodo' (x:xs) (==True)

--6

--a) 
todosPares :: [Int] -> Bool
todosPares (x:xs) = paratodo' (x:xs) even

--b) por las dudas 
multiplo x y = mod x y == 0 

hayMultiplo :: Int -> [Int] -> Bool 
hayMultiplo n xs = existe' xs (multiplo n)

hayMultiplo' :: Int -> [Int] ->  Bool 
hayMultiplo' n x = existe' (map (`mod` n) x)  (==0)

--c) 

sumaCuadrados :: Int -> Int
sumaCuadrados x = sumatoria' [0..x] (^2) 

--d)
factorial' :: Int -> Int
factorial' x = productoria' [1..x] id

--e)  
listaPar :: [Int] -> [Int]
listaPar [] = []
listaPar (x:xs) | mod x 2 == 0 = x : listaPar xs 
    | mod x 2 /= 0 = listaPar xs 

multiplicaPares :: [Int] -> Int
multiplicaPares (x:xs) = productoria' (listaPar (x:xs)) id

--7) Map : Toma 2 argumentos, uno de los cuales es una función
-- Aplica la funcion a cada elemento de xs
-- El resultado es una lista en el mismo orden con la funcion aplicada a cada elemento

-- Filter: Toma 2 argumentos, uno de los cuales es un predicado
--El resultado es una lista en el mismo orden con los elementos que cumplen el predicado 

--La expresion map succ [1, -4, 6, 2, -8] equivale a [2, -3, 7, 3, -7]
--La expresion filter esPositivo [1, -4, 6, 2, -8] equivale a [1, 6, 2]

--8)
duplicar :: [Int] -> [Int]
duplicar [] = []
duplicar (x:xs) = x*2 : duplicar xs 

duplicar' :: [Int] -> [Int]
duplicar' (x:xs) = map (*2) (x:xs)

--9) 

listaPar' :: [Int] -> [Int]
listaPar' [] = []
listaPar' (x:xs) | mod x 2 == 0 = x : listaPar' xs 
    | mod x 2 /= 0 = listaPar' xs 
 
listaPar'' :: [Int] -> [Int]
listaPar'' (x:xs) = filter even (x:xs)

multiplicaPares' (x:xs) = productoria'  (listaPar'' (x:xs)) id 

--10)

--a)
primIgualesA :: (Eq a) => a -> [a] -> [a] 
primIgualesA _ [] = []
primIgualesA n (x:xs) | (x== n ) =  x : primIgualesA n xs 
    | otherwise = []


--b)
primIgualesA' :: (Eq a) => a -> [a] -> [a]
primIgualesA' n (x:xs) = takeWhile (==n) (x:xs) 

--11)  
--a)
primIguales :: (Eq a) => [a] -> [a]
primIguales [x] = [x]
primIguales [] = []
primIguales (x:(y:xs)) |  (x == y) = x : primIguales (y:xs)  
    | otherwise = [x]
--b)
primIguales' :: (Eq a) => [a] -> [a]
primIguales' xs = primIgualesA' (xs!!0) xs


--12) 
cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z [] t = z 
cuantGen op z (x:xs) t = (t x) `op` (cuantGen op z xs t)  

paratodo''' xs f = cuantGen (&&) (True) (xs) (f)   

existe''' xs f = cuantGen (||) (False) (xs) (f) 

sumatoria''' xs f = cuantGen (+) (0) (xs) (f) 

productoria''' xs f = cuantGen (*) (1) (xs) (f) 

--13)
--a) f :: (a, b) -> b 
-- f (x, y) = y 
-- Cubre todos los casos de definicion.

--b) Mal tipado. 

--c) f :: [(a, b)] -> (a, b)
-- f (x:xs) = x 
-- Cubre todos los casos de definicion.

--d) Mal tipado. 

--e) Mal tipado. 

--f) Bien tipado, pero no cubre todos los casos.  

--g) f :: (Int -> Int) -> Int -> Int 
-- f a b = a b 
-- Cubre todos los casos de definicion.

--h) Bien tipado, pero no cubre todos los casos. 

--i) Bien tipado, pero no cubre todos los casos. 

--14)
--a) f (x, y) = y 
-- No tiene respuesta alternativa.

--b) f (x, y) = No tiene solucion.  

--c) f t x = t x 

--d) f _ [] = [] 
--   f t (x:xs) =  t x : f t xs 

--e) f t y z = y (t z)  
