# 📚 C++ Modules - 42 School

## 📋 Tabla de Contenidos General

### [CPP Module 00 - Introduction to C++](#cpp-module-00)
- [Descripción](#descripción-general-cpp00)
- [Reglas Generales](#reglas-generales)
- [Ejercicios](#ejercicios-cpp00)
- [Conceptos Clave](#conceptos-clave-cpp00)

### [CPP Module 01 - Memory & References](#cpp-module-01)
- [Descripción](#descripción-general-cpp01)
- [Ejercicios](#ejercicios-cpp01)
- [Conceptos Clave](#conceptos-clave-cpp01)

---
---

# CPP Module 00

<a name="cpp-module-00"></a>

---

## 🎯 Descripción General {#descripción-general-cpp00}

**Introducción a C++ y POO**. Conceptos: I/O streams, clases, encapsulación, memoria estática.

**Estándar**: C++98

---

## 📜 Reglas Generales

### Compilación
```bash
c++ -Wall -Wextra -Werror -std=c++98 archivo.cpp -o ejecutable
```

### Restricciones Importantes
- ✅ **Permitido**: Librerías estándar de C++ (iostream, string, iomanip, etc.)
- ❌ **Prohibido**: 
  - Funciones de C (printf, malloc, free)
  - `using namespace` (excepto excepciones específicas)
  - `friend` (salvo indicación)
  - STL (hasta módulos 08-09)
  - Memoria dinámica (`new`/`delete`, `malloc`/`free`)
  - C++11 o superior

### Convenciones de Nombres
- **Clases**: `UpperCamelCase` (ejemplo: `PhoneBook`)
- **Archivos**: Deben coincidir con el nombre de la clase
  - `ClassName.hpp` (header)
  - `ClassName.cpp` (implementación)
- **Directorios**: `ex00`, `ex01`, etc.

### Headers
- Usar **include guards** en todos los `.hpp`
  ```cpp
  #ifndef CLASSNAME_HPP
  #define CLASSNAME_HPP
  // ...
  #endif
  ```
- Headers deben ser **independientes** (incluir sus propias dependencias)

---

## 🚀 Ejercicios {#ejercicios-cpp00}

### ex00: Megaphone

Convierte argumentos a mayúsculas.

```bash
./megaphone "hello world"
# Output: HELLO WORLD
```

**Conceptos**: `std::cout`, `argc/argv`, `toupper()`

---

### ex01: PhoneBook

Agenda telefónica con máximo 8 contactos.

**Comandos**: `ADD`, `SEARCH`, `EXIT`

**Estructura**:
```
ex01/
├── main.cpp
├── PhoneBook.hpp
├── PhoneBook.cpp
├── Contact.hpp
├── Contact.cpp
└── Makefile
```

**Comandos**: `ADD`, `SEARCH`, `EXIT`

**Clases**:
- `Contact`: Almacena información de un contacto (getters/setters)
- `PhoneBook`: Gestiona array de 8 contactos

```cpp
class Contact {
private:
    std::string firstName, lastName, nickname;
    std::string phoneNumber, darkestSecret;
public:
    std::string getFirstName();
    void setFirstName(std::string name);
};

class PhoneBook {
private:
    Contact contacts[8];  // Array fijo
    int count, index;     // Control de contactos
public:
    PhoneBook();  // Constructor
    void addContact();
};
```

**Lógica circular**: `index = (index + 1) % 8` para sobrescribir el más antiguo.

---

## 💡 Conceptos Clave {#conceptos-clave-cpp00}

### 1. Clases y Encapsulación

```cpp
class MyClass {
private:
    int value;  // Atributo privado
public:
    int getValue() { return value; }  // Getter
    void setValue(int v) { value = v; }  // Setter
};
```

### 2. Constructores

```cpp
class PhoneBook {
public:
    PhoneBook();  // Constructor
};

// Initialization list (C++98)
PhoneBook::PhoneBook() : count(0), index(0) {}
```

**⚠️ C++98**: NO se puede `int count = 0;` en la clase. Usar initialization list.

### 3. Getters y Setters

- **Getter**: Devuelve valor de atributo privado
- **Setter**: Modifica valor de atributo privado
- **Ventaja**: Control y validación de acceso

### 4. Paso por Referencia

```cpp
void func(std::string& str);  // No copia, usa el original
```

- Evita copias costosas
- Cambios afectan al original
- Usar `&` para objetos grandes

### 5. `std::string`

```cpp
std::string str = "Hello";
str.length();     // Tamaño
str.empty();      // true si vacío
str.substr(0, 3); // "Hel"
```

### 6. Memoria Estática

```cpp
Contact contacts[8];  // ✓ Array fijo (permitido)
int* ptr = new int;   // ❌ Dinámica (prohibida en CPP_00)
```

---

## ✨ Puntos Clave

- **C++98**: No `auto`, `nullptr`, range-based for
- **Encapsulación**: Atributos `private`, getters/setters
- **Constructores**: Usar initialization list
- **Referencias**: `&` para evitar copias
- **Include guards**: Obligatorios en `.hpp`
- **Namespaces**: `std::cout`, nunca `using namespace std`

---

**Autor**: Laura Giner  
**Fecha**: Diciembre 2025

---
---

# CPP Module 01

<a name="cpp-module-01"></a>

## 🎯 Descripción General {#descripción-general-cpp01}

El **Módulo CPP_01** profundiza en la gestión de memoria y referencias en C++. Los temas principales son:
- Asignación de memoria dinámica con `new` y `delete`
- Diferencias entre punteros y referencias
- Punteros a funciones miembro
- Manipulación de archivos y strings
- `switch` statements

**Estándar**: C++98

---

## 🚀 Ejercicios {#ejercicios-cpp01}

### ex00-ex01: Zombies (new/delete y arrays)

**Conceptos**: Memoria dinámica en stack vs heap

```cpp
// Stack - destrucción automática
Zombie z("Stack");

// Heap - destrucción manual
Zombie* z = new Zombie("Heap");
delete z;

// Arrays
Zombie* horde = new Zombie[10];
delete[] horde;  // ¡[] obligatorio!
```

### ex02: Punteros vs Referencias

```cpp
std::string str = "HI THIS IS BRAIN";
std::string* stringPTR = &str;  // Puntero
std::string& stringREF = str;   // Referencia

// Acceso
*stringPTR;  // Dereferencia con *
stringREF;   // Acceso directo
```

| Puntero | Referencia |
|---------|------------|
| Puede ser NULL | DEBE inicializarse |
| Se puede reasignar | NO cambia destino |
| `*ptr` para acceder | Acceso directo |

### ex03: Weapon - Referencias vs Punteros

**HumanA** - Referencia (siempre tiene arma):
```cpp
class HumanA {
    Weapon& weapon;  // Inicializada en constructor
public:
    HumanA(std::string n, Weapon& w) : weapon(w) {}
};
```

**HumanB** - Puntero (puede no tener arma):
```cpp
class HumanB {
    Weapon* weapon;  // Puede ser NULL
public:
    HumanB(std::string n) : weapon(NULL) {}
    void setWeapon(Weapon& w) { weapon = &w; }
};
```

### ex04: Sed is for losers

Reemplazar strings en archivos sin usar `std::string::replace`.

```cpp
// Buscar todas las ocurrencias
while ((pos = line.find(s1, pos)) != std::string::npos)
{
    line.erase(pos, s1.length());
    line.insert(pos, s2);
    pos += s2.length();  // Evita bucle infinito
}
```

**`std::string::npos`**: Constante que significa "no encontrado"

**¿Por qué `pos += s2.length()`?** Para buscar después del texto insertado y evitar bucles infinitos.

### ex05-ex06: Harl - Punteros a Miembro y Switch

**Punteros a funciones miembro**:
```cpp
void (Harl::*functions[4])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

// Llamada
(this->*functions[i])();
```

**Switch con fall-through** (ex06):
```cpp
switch (levelIndex)
{
    case 0:  // DEBUG
        debug();
        /* fall through */
    case 1:  // INFO
        info();
        /* fall through */
    case 2:  // WARNING
        warning();
        /* fall through */
    case 3:  // ERROR
        error();
        break;
    default:
        std::cout << "[ Probably complaining... ]\
";
}
```

**Fall-through**: Pasa al siguiente `case` sin `break`. Comentarios `/* fall through */` son necesarios para el compilador.

---

## 💡 Conceptos Clave {#conceptos-clave-cpp01}

### 1. Memoria Dinámica

```cpp
// Objeto único
Type* ptr = new Type;
delete ptr;

// Array
Type* arr = new Type[n];
delete[] arr;  // ¡[] OBLIGATORIO!
```

**Stack vs Heap**:
- **Stack**: Automático, rápido, destrucción al salir del scope
- **Heap**: Manual (`new`/`delete`), persiste hasta `delete`, tamaño flexible

### 2. Referencias

```cpp
int& ref = x;  // DEBE inicializarse
ref = 10;      // Modifica x
```

**Cuándo usar**:
- Parámetros (evitar copias): `void func(std::string& str)`
- Objeto siempre existe
- No necesitas NULL ni reasignar

### 3. Archivos

```cpp
std::ifstream infile("file.txt");
std::ofstream outfile("out.txt");

// Streams SIEMPRE por referencia
void process(std::ifstream& file);
```

### 4. Métodos de `std::string`

```cpp
str.find(substr);           // Busca, devuelve pos o npos
str.erase(pos, len);        // Borra len caracteres desde pos
str.insert(pos, str2);      // Inserta en pos
str.length();               // Tamaño
str.empty();                // true si vacío
str.c_str();                // Convierte a char*
```

### 5. Switch Statement

```cpp
switch (intVariable)  // Solo int, char, enum
{
    case 0:
        // código
        break;  // Sale del switch
    case 1:
        // código
        // Sin break - continúa (fall-through)
    default:
        // Si ningún case coincide
}
```

### 6. Initialization Lists

```cpp
class MyClass {
    int& ref;  // Referencias deben ir aquí
public:
    MyClass(int& r) : ref(r) {}  // Initialization list
};
```

**Obligatorias para**: referencias, `const`, clases sin constructor por defecto.

---

## ✨ Resumen

| Ejercicio | Concepto |
|-----------|----------|
| ex00-01 | `new`/`delete`, `new[]`/`delete[]` |
| ex02 | Punteros vs referencias |
| ex03 | Cuándo usar cada uno, initialization lists |
| ex04 | Archivos, `find()`, `npos` |
| ex05 | Punteros a funciones miembro |
| ex06 | `switch`, fall-through |

---

**Autor**: Laura Giner  
**Fecha**: Enero 2026  
**Proyecto**: 42 School - CPP Module 01
