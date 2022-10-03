--1
-{
Parcial 1 - Algoritmos I Taller: Tema E
Ejercicio 1

Se van a implementar algunos aspectos de las dedicaciones de las Personas  en Haskell. 

a) Definir el tipo Dedicacion que consta de los constructores: Simple, Semi,  Full, Investigador. Los constructores no toman parámetros. El tipo Dedicacion no debe estar en la clase Eq. Luego programa la función usando pattern matching:
misma_dedicacion :: Dedicacion -> Dedicacion -> Bool

que dados dos valores p1 y p2 del tipo Dedicacion debe devolver True cuando p1 y p2 son la misma dedicación (se construyen con el mismo constructor) y False en caso contrario.
Si se usan más de cinco casos, o menos de cinco casos este apartado sumará menos puntaje.
b) Programar la función
horas_trabajo :: Dedicacion -> Cantidad

Si es Simple devuelve 10 
Si es Semi devuelve 20 
Full devuelve 50 
Investigador devuelve 60
Cantidad debe ser definida como sinónimo de Int
c) Agregar al tipo Persona la Dedicacion a los constructores Decane, Docente y NoDocente.
d) Incluir el tipo Dedicacion en la clase Ord de manera tal que un dedicacion se considere mayor que otra si su valor según la función horas_trabajo es más grande.

Ejercicio 2
a) Programar de manera recursiva la función

solo_dedicacion :: [Persona] -> Dedicacion -> [Persona]


que dada una lista de personas ps y un dedicacion r devuelve una lista con las personas de ps que tienen dedicación r. 
b) Escribir una lista de personas con al menos tres elementos, donde al menos uno de ellos debe tener dedicación, y otro no debe tener dedicación.
c) Escribir el resultado de solo_dedicacion para la lista del punto b)
Ejercicio 3
 Basados en el tipo ListaAsoc del Proyecto 2, programar la función:
la_mismo_valor :: ListaAsoc a b -> b -> ListaAsoc a b

que dada una lista de asociaciones la, devuelve una nueva lista de asociaciones con las asociaciones de la cuyos valores son iguales al segundo parámetro. Completar el tipado de la función para incluir los type clases necesarios para programarla.
Ejercicio 4*
a) Programar la función
dar_subarbol :: a -> Arbol a -> Arbol a

que dado un valor e de tipo a y un árbol as devuelve el subarbol que tiene como raiz a e o Hoja en caso de no existir. Completar el tipado de la función para incluir los type classes necesarios para programarla.
b) Inventar un ejemplo de uso de la función creando un árbol con al menos 3 elementos
c) Escribir el resultado de la función aplicada al ejemplo del inciso b)

-}
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
