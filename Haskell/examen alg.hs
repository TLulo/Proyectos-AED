--1
--a 
data Dedicacion = Simple | Semi | Full | Investigador deriving (Ord,Eq,Show)

misma_dedicacion :: Dedicacion -> Dedicacion -> Bool

misma_dedicacion Simple Simple = True
misma_dedicacion Semi Semi = True
misma_dedicacion Full Full = True
misma_dedicacion Investigador Investigador = True
misma_dedicacion _ _= False

--b
type Cantidad = Int
horas_trabajo :: Dedicacion -> Cantidad

horas_trabajo Simple = 10
horas_trabajo Semi = 20
horas_trabajo Full = 50
horas_trabajo Investigador = 60

--c
data Persona = Decane Dedicacion | Docente Dedicacion | NoDocente Dedicacion | Estudiante deriving (Show)

--2
--a
solo_dedicacion :: [Persona] -> Dedicacion -> [Persona]

solo_dedicacion [] r = []
solo_dedicacion (Decane x:ps) r
    | x == r = [Decane x]++ solo_dedicacion ps r
    |otherwise = solo_dedicacion ps r
solo_dedicacion (Docente x:ps) r
    | x == r = [Docente x]++ solo_dedicacion ps r
    |otherwise = solo_dedicacion ps r
solo_dedicacion (NoDocente x:ps) r
    | x == r = [Docente x]++ solo_dedicacion ps r
    |otherwise = solo_dedicacion ps r
solo_dedicacion (_:ps) r = solo_dedicacion ps r 


--b
--[Decane Simple,Estudiante,Docente Full] Simple
--c
--[Decane Simple]
--3
--a
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving (Show)

la_mismo_valor ::(Eq b) => ListaAsoc a b -> b -> ListaAsoc a b
la_mismo_valor Vacia x = Vacia
la_mismo_valor (Nodo a b z) x
    |b == x = (Nodo a b (la_mismo_valor z x))
    |otherwise = la_mismo_valor z x

--4
data Arbol a =Hoja | Rama (Arbol a) a (Arbol a) deriving Show
--a
type Prefijos = Arbol String

can, cana, canario, canas, cant, cantar, canto :: Prefijos

can = Rama cana "can" cant
cana = Rama canario "a" canas
canario = Rama Hoja "rio" Hoja
canas = Rama Hoja  "s" Hoja
cant = Rama cantar "t" canto
cantar = Rama Hoja "ar" Hoja
canto = Rama Hoja "o" Hoja

dar_subarbol :: Eq a => a -> Arbol a -> Arbol a

dar_subarbol e Hoja = Hoja
dar_subarbol e (Rama x y z)
    | y == e = (Rama x y z)
    |otherwise = dar_subarbol e (Rama (dar_subarbol e x) y (dar_subarbol e z))