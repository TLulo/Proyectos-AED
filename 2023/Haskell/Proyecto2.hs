--1.a
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq,Show)

--1.b
titulo :: Carrera -> String

titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Astronomia = "Licenciatura en Astronomia"

--1.c (2.deriving añadidos)
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Ord,Eq,Show)

--1.d
cifradoAmericano :: NotaBasica -> Char

cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

--3.a
minElemento ::Ord a => [a] -> a

minElemento [x] = x
minElemento (x:xs) = min x (minElemento xs)

--3.b
minElemento' :: (Ord a,Bounded a) => [a] -> a

minElemento' [] = minBound
minElemento' [x] = x
minElemento' (x:xs) = min x (minElemento' xs)

--4.a
type Ingreso = Int

data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar deriving (Show,Eq)
data Area = Administrativa | Ensenanza | Economica | Postgrado deriving (Eq,Show)

data Persona = Decane | Docente Cargo | NoDocente Area | Estudiante Carrera Ingreso deriving (Eq,Show)

--4.b
-- Docente :: Cargo -> Persona
--4.c
cuantos_doc :: [Persona] -> Cargo -> Int

cuantos_doc [] y = 0

cuantos_doc ((Docente x):xs) y
    |x == y = 1 + cuantos_doc xs y
    |otherwise = 0 + cuantos_doc xs y
cuantos_doc (_:xs) y = 0 + cuantos_doc xs y

--4.d
cuantos_doc' :: [Persona] -> Cargo -> Int 
cuantos_doc' [] y = 0
cuantos_doc' (xs) y = length (filter ((Docente y)==) xs)

--5.a
data Alteracion = Bemol | Sostenido | Natural deriving (Ord,Eq)
data NotaMusical = Nota NotaBasica Alteracion deriving (Ord,Eq)

sonido :: NotaBasica -> Int

sonido Do = 1
sonido Re = 3
sonido Mi = 5
sonido Fa = 6
sonido Sol = 8
sonido La = 10
sonido Si = 12

--5.b
sonidoCromatico :: NotaMusical -> Int

sonidoCromatico (Nota x Sostenido) = sonido x + 1
sonidoCromatico (Nota x Bemol) = sonido x - 1
sonidoCromatico (Nota x Natural) = sonido x

--6
primerElemento :: [a] -> Maybe (a)

primerElemento [] = Nothing
primerElemento (x:xs) = Just x

--7
data Cola = VaciaC | Encolada Persona Cola deriving (Show)

--7.a.1
atender :: Cola -> Maybe (Cola)

atender VaciaC = Nothing
atender (Encolada x y) = Just y

--7.a.2
encolar :: Persona -> Cola -> Cola

encolar a VaciaC = Encolada a VaciaC
encolar a (Encolada x y) = (Encolada x (encolar a y))

--7.a.3
busca :: Cola -> Cargo -> Maybe Persona

busca VaciaC w = Nothing
busca (Encolada (Docente x) y) z
    | x == z =Just (Docente x)
    |otherwise = busca y z
busca (Encolada _ y) z = busca y z
--7.b
--Cola Tiene un parecido al tipo Lista

--8
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving (Eq, Ord, Show) 

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

--8.a
type GuiaTel = ListaAsoc String Int
--8.b.1
la_long :: ListaAsoc a b -> Int

la_long Vacia = 0
la_long (Nodo a b x) = 1 + la_long(x)

--8.b.2
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b

la_concat Vacia Vacia = Vacia
la_concat y Vacia = y
la_concat Vacia x= x
la_concat (Nodo a b x) (Nodo c d y) = (Nodo a b (la_concat x (Nodo c d y)))

--8.b.3
la_agregar :: ListaAsoc a b -> a -> b -> ListaAsoc a b

la_agregar Vacia a b = (Nodo a b Vacia)
la_agregar (Nodo x y z) a b = (Nodo x y (Nodo a b z))

--8.b.4
la_pares :: ListaAsoc a b -> [(a,b)]

la_pares Vacia = []
la_pares (Nodo a b z) = [(a,b)]++(la_pares z)

--8.b.5
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe (b)

la_busca Vacia x = Nothing
la_busca (Nodo a b z) x
    |a==x = Just b
    |otherwise = la_busca z x

--8.b.6
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b

la_borrar x Vacia = Vacia
la_borrar x (Nodo a b z)
    |x == a = la_borrar x z
    |otherwise = (Nodo a b (la_borrar x z))

--9
data Arbol a = Hoja | Rama (Arbol a) a (Arbol a)

type Prefijos = Arbol String

can, cana, canario, canas, cant, cantar, canto :: Prefijos

can = Rama cana "can" cant
cana = Rama canario "a" canas
canario = Rama Hoja "rio" Hoja
canas = Rama Hoja  "s" Hoja
cant = Rama cantar "t" canto
cantar = Rama Hoja "ar" Hoja
canto = Rama Hoja "o" Hoja

--9.a
a_long :: Arbol a -> Int

a_long Hoja = 1
a_long (Rama x a y) = 1 + a_long(x)+ a_long(y)

--9.b
a_hojas :: Arbol a -> Int

a_hojas Hoja = 1
a_hojas (Rama x a y) = 0 + a_hojas(x) + a_hojas(y)

--9.c
a_inc :: Num a => Arbol a -> Arbol a

a_inc Hoja = Hoja
a_inc (Rama x a y) = (Rama (a_inc(x)) (a+1) (a_inc(y)))

--9.d

a_map :: (a->b) -> Arbol a -> Arbol b

a_map z Hoja= Hoja 
a_map z (Rama x a y) = (Rama (a_map z x) (z a) (a_map z y))

a_inc' :: Num a => Arbol a -> Arbol a
a_inc' (Rama x a y)= a_map (+1) (Rama x a y)