# 📚 CPP Module 00 - Introduction to C++

## 📋 Tabla de Contenidos
- [Descripción General](#descripción-general)
- [Reglas Generales](#reglas-generales)
- [Ejercicios](#ejercicios)
  - [ex00: Megaphone](#ex00-megaphone)
  - [ex01: PhoneBook](#ex01-phonebook)
- [Conceptos Clave de C++](#conceptos-clave-de-c)
- [Compilación y Ejecución](#compilación-y-ejecución)

---

## 🎯 Descripción General

El **Módulo CPP_00** es una introducción a la programación en C++. Explora conceptos fundamentales como:
- Sintaxis básica de C++ (I/O streams, variables, funciones)
- Programación Orientada a Objetos (POO)
- Clases y encapsulación
- Gestión de memoria estática

Este módulo utiliza el estándar **C++98** para comprender las bases del lenguaje antes de usar características modernas.

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

## 🚀 Ejercicios

### ex00: Megaphone

**Descripción**: Programa que convierte argumentos de línea de comandos a mayúsculas.

**Archivos**:
- `megaphone.cpp`
- `Makefile`

**Uso**:
```bash
./megaphone "shhhhh... I think the students are asleep..."
# Output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# Output: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Conceptos aplicados**:
- Uso de `std::cout` y `std::endl`
- Manejo de argumentos (`argc`, `argv`)
- Función `toupper()` de `<cctype>`

---

### ex01: PhoneBook

**Descripción**: Agenda telefónica simple que almacena hasta 8 contactos con funcionalidad de búsqueda.

**Archivos**:
```
ex01/
├── main.cpp
├── PhoneBook.hpp
├── PhoneBook.cpp
├── Contact.hpp
├── Contact.cpp
└── Makefile
```

**Comandos**:
- `ADD`: Añadir un nuevo contacto (sobrescribe el más antiguo si hay 8)
- `SEARCH`: Muestra tabla de contactos y permite ver detalles por índice
- `EXIT`: Cierra el programa

**Uso**:
```bash
./phonebook
Please, enter one option: ADD, SEARCH or EXIT
> ADD
Enter a first name:
> Laura
Enter a last name:
> Giner
...

> SEARCH
|     Index|First Name| Last Name|  Nickname|
|----------|----------|----------|----------|
|         0|     Laura|     Giner|       lau|
|         1|     Pablo|  Gonzalez|   pablito|
Enter an index to see all the information: 0

First name: Laura
Last name: Giner
Nickname: lau
Phone number: 123456789
Dark secret: Loves coding
```

**Estructura de Clases**:

#### Clase `Contact`
Encapsula la información de un contacto individual.

```cpp
class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    int id;  // Identificador único

public:
    // Getters
    std::string getFirstName();
    int getId();
    
    // Setters
    void setFirstName(std::string name);
    void setId(int contactId);
};
```

#### Clase `PhoneBook`
Gestiona el array de contactos y la lógica de la agenda.

```cpp
class PhoneBook {
private:
    Contact contacts[8];   // Array fijo (memoria estática)
    int count;             // Contactos actuales (máx 8)
    int index;             // Siguiente posición a sobrescribir
    int totalContacts;     // Contador total de contactos añadidos

public:
    PhoneBook();  // Constructor
    void addContact();
    int createPhonebook();
    int enterIndex(std::string input);
};
```

**Variables de control**:
- `count`: Número de contactos actuales (máximo 8, nunca decrece hasta llenarse)
- `index`: Posición circular para sobrescribir (`index = (index + 1) % 8`)
- `totalContacts`: ID único que incrementa indefinidamente

---

## 💡 Conceptos Clave de C++

### 1. Constructores
Método especial que **inicializa los atributos** de una clase cuando se crea un objeto.

```cpp
// En PhoneBook.hpp
class PhoneBook {
public:
    PhoneBook();  // Declaración del constructor
};

// En PhoneBook.cpp
PhoneBook::PhoneBook() : count(0), index(0), totalContacts(0)
{
    // Initialization list (C++98 compatible)
}
```

**⚠️ Importante**: En C++98 **NO** se puede inicializar en la declaración:
```cpp
// ❌ PROHIBIDO en C++98
class PhoneBook {
    int count = 0;  // Error!
};

// ✅ CORRECTO - Usar initialization list en el constructor
PhoneBook::PhoneBook() : count(0) {}
```

---

### 2. Getters y Setters (Encapsulación)

**Getters**: Obtienen el valor de un atributo privado.
```cpp
std::string Contact::getFirstName()
{
    return firstName;
}
```

**Setters**: Modifican el valor de un atributo privado.
```cpp
void Contact::setFirstName(std::string name)
{
    firstName = name;
}
```

**Ventajas**:
- Control sobre acceso a datos
- Validación de valores (ej: verificar que el nombre no esté vacío)
- Encapsulación: ocultación de detalles internos

---

### 3. Paso por Referencia vs Paso por Valor

#### Paso por Valor (crea una copia)
```cpp
void saveContact(Contact contact);  // Copia el objeto completo
```
- ❌ **Ineficiente**: Copia toda la información del contacto
- ❌ **Cambios no afectan** al original

#### Paso por Referencia (usa el original)
```cpp
void checkEmpty(std::string &input, std::string message);
```
- ✅ **Eficiente**: No copia, usa el objeto original
- ✅ **Cambios SÍ afectan** al original
- ✅ **Ahorra memoria** especialmente con objetos grandes

**Cuándo usar cada uno**:
- **Referencia (`&`)**: Cuando quieres modificar el parámetro o evitar copias costosas
- **Valor**: Cuando necesitas una copia independiente o datos simples (int, char)

---

### 4. `std::string` - Primera Clase de C++

En C++, `std::string` es una **clase** (como `Contact` o `PhoneBook`).

```cpp
std::string field = "Laura";

// Métodos de la clase string
field.length();      // Devuelve 5
field.empty();       // Devuelve false
field.substr(0, 3);  // Devuelve "Lau"
field.c_str();       // Convierte a C-string (char*)
```

**Diferencia con C**:
- C: `char str[]` + funciones (`strlen()`, `strcpy()`)
- C++: `std::string` + métodos (`str.length()`, `str.substr()`)

---

### 5. Memoria Estática vs Dinámica

#### Memoria Estática (Permitida)
```cpp
Contact contacts[8];     // Array fijo en tiempo de compilación
std::string input;       // Variable local (stack)
int count;               // Variable miembro
```

#### Memoria Dinámica (Prohibida en este ejercicio)
```cpp
Contact* contacts = new Contact[8];  // ❌ PROHIBIDO
delete[] contacts;

int* ptr = (int*)malloc(sizeof(int));  // ❌ PROHIBIDO (función de C)
free(ptr);
```

**Razón**: Este módulo se centra en **RAII** (Resource Acquisition Is Initialization) - dejar que el compilador gestione la memoria automáticamente.

---

## 🛠️ Compilación y Ejecución

### ex00: Megaphone
```bash
cd ex00
make
./megaphone "Hello World"
make clean  # Elimina .o
make fclean # Elimina .o y ejecutable
```

### ex01: PhoneBook
```bash
cd ex01
make
./phonebook
make re  # Recompila todo desde cero
```

---

## 📚 Recursos Útiles

- [CPlusPlus Reference](https://cplusplus.com/reference/)
- [Learn C++](https://www.learncpp.com/)
- [C++98 Standard](https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf)

---

## ✨ Puntos Clave a Recordar

1. **C++98**: No usar características modernas (auto, nullptr, range-based for)
2. **Encapsulación**: Atributos `private`, acceso mediante getters/setters
3. **Constructors**: Usar initialization list para inicializar miembros
4. **Referencias**: Preferir `&` para evitar copias innecesarias
5. **Memoria**: Solo estática (arrays fijos, variables locales)
6. **Include guards**: Obligatorios en todos los `.hpp`
7. **Namespaces**: Escribir `std::cout`, nunca `using namespace std`
8. **Validación**: Siempre verificar entrada del usuario

---

**Autor**: Laura Giner  
**Fecha**: Diciembre 2025  
**Proyecto**: 42 School - CPP Module 00
