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

### [CPP Module 02 - Orthodox Canonical Form](#cpp-module-02)
- [Descripción](#descripción-general-cpp02)
- [Ejercicios](#ejercicios-cpp02)
- [Conceptos Clave](#conceptos-clave-cpp02)

### [CPP Module 03 - Inheritance](#cpp-module-03)
- [Descripción](#descripción-general-cpp03)
- [Ejercicios](#ejercicios-cpp03)
- [Conceptos Clave](#conceptos-clave-cpp03)

### [CPP Module 04 - Polymorphism](#cpp-module-04)
- [Descripción](#descripción-general-cpp04)
- [Ejercicios](#ejercicios-cpp04)
- [Conceptos Clave](#conceptos-clave-cpp04)

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

---
---

# CPP Module 02

<a name="cpp-module-02"></a>

## 🎯 Descripción General {#descripción-general-cpp02}

El **Módulo CPP_02** introduce la **Forma Canónica Ortodoxa** (Orthodox Canonical Form) y los **números de punto fijo** (fixed-point numbers). Los temas principales son:
- Las cuatro funciones canónicas obligatorias
- Constructor de copia vs operador de asignación
- Sobrecarga de operadores
- Números de punto fijo (representación y conversiones)
- Operadores de incremento/decremento

**Estándar**: C++98

---

## 🚀 Ejercicios {#ejercicios-cpp02}

### ex00: My First Class in Orthodox Canonical Form

Implementación básica de la clase `Fixed` con las 4 funciones canónicas.

**Forma Canónica Ortodoxa**:
```cpp
class Fixed {
private:
    int value;                        // Valor del número de punto fijo
    static const int fractionalBits;  // Bits fraccionarios (8)
    
public:
    Fixed();                                // Constructor por defecto
    Fixed(const Fixed& other);             // Constructor de copia
    Fixed& operator=(const Fixed& other);  // Operador de asignación
    ~Fixed();                               // Destructor
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
```

**Diferencias clave**:
```cpp
Fixed a;
Fixed b(a);   // Constructor de copia
Fixed c = a;  // Constructor de copia también (inicialización)

Fixed d;
d = a;        // Operador de asignación (objeto ya existe)
```

### ex01: Towards a More Useful Fixed-Point Number Class

Añade conversiones entre enteros, floats y números de punto fijo.

**Conversiones**:
```cpp
class Fixed {
public:
    Fixed(const int n);         // Constructor desde int
    Fixed(const float f);       // Constructor desde float
    
    float toFloat(void) const;  // Convierte a float
    int toInt(void) const;      // Convierte a int
};

// Sobrecarga de << para imprimir
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

**Cálculos de punto fijo**:
```cpp
// Int → Fixed: Desplazar bits a la izquierda
value = n << fractionalBits;

// Float → Fixed: Multiplicar por 2^fractionalBits y redondear
value = roundf(f * (1 << fractionalBits));

// Fixed → Float: Dividir por 2^fractionalBits
return (float)value / (1 << fractionalBits);

// Fixed → Int: Desplazar bits a la derecha
return value >> fractionalBits;
```

### ex02: Now We're Talking

Sobrecarga completa de operadores de comparación y aritméticos.

**Operadores de comparación**:
```cpp
bool operator>(const Fixed& other) const;
bool operator<(const Fixed& other) const;
bool operator>=(const Fixed& other) const;
bool operator<=(const Fixed& other) const;
bool operator==(const Fixed& other) const;
bool operator!=(const Fixed& other) const;
```

**Operadores aritméticos**:
```cpp
Fixed operator+(const Fixed& other) const;
Fixed operator-(const Fixed& other) const;
Fixed operator*(const Fixed& other) const;
Fixed operator/(const Fixed& other) const;
```

**Incremento/Decremento**:
```cpp
// Pre-incremento: ++a (retorna referencia)
Fixed& operator++();    // Pre-incremento
Fixed& operator--();    // Pre-decremento

// Post-incremento: a++ (retorna copia)
Fixed operator++(int);  // Post-incremento (int dummy)
Fixed operator--(int);  // Post-decremento (int dummy)
```

**Min/Max estáticos**:
```cpp
static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);
```

---

## 💡 Conceptos Clave {#conceptos-clave-cpp02}

### 1. Forma Canónica Ortodoxa

**Las 4 funciones obligatorias**:

```cpp
class Example {
public:
    Example();                                // Constructor por defecto
    Example(const Example& other);            // Constructor de copia
    Example& operator=(const Example& other); // Operador de asignación
    ~Example();                               // Destructor
};
```

**¿Cuándo se llama cada una?**
- **Constructor por defecto**: `Example obj;`
- **Constructor de copia**: `Example obj2(obj1);` o `Example obj2 = obj1;`
- **Operador de asignación**: `obj2 = obj1;` (cuando obj2 ya existe)
- **Destructor**: Al salir del scope o `delete`

**Implementación del operador de asignación**:
```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)  // Protección contra auto-asignación
        this->value = other.getRawBits();
    return *this;  // Permite encadenamiento: a = b = c
}
```

### 2. Números de Punto Fijo

**¿Por qué punto fijo?**
- Los `float` son imprecisos para cálculos exactos
- Punto fijo usa enteros, más rápido en sistemas sin FPU

**Representación**:
```
32 bits totales
├─ 24 bits enteros (parte entera)
└─ 8 bits fraccionarios (parte decimal)

Ejemplo: 42.75
42 = 42 << 8 = 10752
0.75 = 0.75 * 256 = 192
Total = 10752 + 192 = 10944 (representación interna)
```

**Conversiones**:
```cpp
// Int → Fixed
int n = 42;
int fixed = n << 8;  // Multiplica por 256

// Float → Fixed
float f = 42.42f;
int fixed = roundf(f * 256);  // Multiplica y redondea

// Fixed → Float
int fixed = 10944;
float f = (float)fixed / 256;  // Divide por 256

// Fixed → Int
int n = fixed >> 8;  // Divide por 256 (pierde decimales)
```

### 3. Sobrecarga de Operadores

**Operadores miembro vs no miembro**:

```cpp
// Miembro: this es el operando izquierdo
class Fixed {
    Fixed operator+(const Fixed& other) const {
        return Fixed(this->toFloat() + other.toFloat());
    }
};

// No miembro: para operator<< (ostream es el izquierdo)
std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;  // Permite encadenamiento: cout << a << b
}
```

**Pre vs Post incremento**:
```cpp
Fixed& operator++() {      // Pre-incremento: ++a
    this->value++;
    return *this;          // Retorna el objeto modificado
}

Fixed operator++(int) {    // Post-incremento: a++
    Fixed temp(*this);     // Guarda copia del valor original
    this->value++;
    return temp;           // Retorna el valor ANTES del incremento
}
```

**Parámetro `int` dummy**: Diferencia pre de post-incremento en compilación.

### 4. Funciones Estáticas

```cpp
static Fixed& min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;  // Retorna referencia
}

// Uso
Fixed a(10), b(20);
Fixed& menor = Fixed::min(a, b);  // a
```

**`static`**: No necesita instancia de la clase, se llama con `ClassName::function()`.

### 5. Const Correctness

```cpp
// Sobrecarga para const y no-const
static Fixed& min(Fixed& a, Fixed& b);              // Para objetos no-const
static const Fixed& min(const Fixed& a, const Fixed& b);  // Para const

// Métodos const: no modifican el objeto
int getRawBits(void) const;  // Puede ser llamado en objetos const
```

---

## ✨ Resumen

| Ejercicio | Concepto |
|-----------|----------|
| ex00 | Forma Canónica Ortodoxa (4 funciones) |
| ex01 | Conversiones int/float, sobrecarga `<<` |
| ex02 | Todos los operadores, pre/post-incremento |

**Puntos clave**:
- Siempre implementar las 4 funciones canónicas
- Operador `=` debe proteger contra auto-asignación
- Pre-incremento retorna referencia, post-incremento retorna copia
- Punto fijo: desplazar bits (`<<`, `>>`) para conversiones int
- `const` permite usar objetos constantes con funciones que no modifican

---

**Autor**: Laura Giner  
**Fecha**: Enero 2026  
**Proyecto**: 42 School - CPP Module 02

---
---

# CPP Module 03

<a name="cpp-module-03"></a>

## 🎯 Descripción General {#descripción-general-cpp03}

El **Módulo CPP_03** introduce la **herencia** (inheritance) en C++. Los temas principales son:
- Herencia pública, protegida y privada
- Constructores y destructores en jerarquías
- Sobrescritura de métodos
- Herencia múltiple y el Diamond Problem
- Herencia virtual para resolver ambigüedades

**Estándar**: C++98

---

## 🚀 Ejercicios {#ejercicios-cpp03}

### ex00: ClapTrap

Clase base que representa un robot con vida, energía y daño de ataque.

```cpp
class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints;      // Vida (10)
    unsigned int energyPoints;   // Energía (10)
    unsigned int attackDamage;   // Daño (0)
    
public:
    ClapTrap(std::string name);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
```

**Mecánicas**:
- `attack()`, `takeDamage()`, `beRepaired()` cuestan 1 punto de energía
- Sin energía o vida, no puede hacer acciones
- `beRepaired()` restaura vida

### ex01: ScavTrap - Herencia Simple

`ScavTrap` hereda de `ClapTrap` con atributos mejorados.

```cpp
class ScavTrap : public ClapTrap  // Herencia pública
{
public:
    ScavTrap(std::string name);
    void attack(const std::string& target);  // Sobrescribe
    void guardGate();  // Método único de ScavTrap
};
```

**Valores de ScavTrap**:
- Hit Points: 100 (vs 10 de ClapTrap)
- Energy Points: 50 (vs 10)
- Attack Damage: 20 (vs 0)

**Constructores/Destructores**:
```
Construcción: ClapTrap → ScavTrap
Destrucción: ScavTrap → ClapTrap (orden inverso)
```

**Sobrescritura de métodos**:
```cpp
void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << name << " attacks!";  // Mensaje diferente
}
```

### ex02: FragTrap - Más Herencia

Añade `FragTrap`, otra clase derivada de `ClapTrap`.

```cpp
class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    void highFivesGuys(void);  // Método único
};
```

**Valores de FragTrap**:
- Hit Points: 100
- Energy Points: 100
- Attack Damage: 30

**Jerarquía**:
```
       ClapTrap
      /        \
 ScavTrap    FragTrap
```

### ex03: DiamondTrap - Herencia Múltiple

`DiamondTrap` hereda de `ScavTrap` Y `FragTrap` → **Diamond Problem**.

**Sin herencia virtual** (problema):
```
       ClapTrap
      /        \
 ScavTrap    FragTrap
      \        /
     DiamondTrap
```
Problema: `DiamondTrap` tiene **dos copias** de `ClapTrap` → ambigüedad.

**Solución: Herencia virtual**:
```cpp
class ScavTrap : virtual public ClapTrap {};
class FragTrap : virtual public ClapTrap {};
class DiamondTrap : public ScavTrap, public FragTrap {};
```

Ahora hay **una sola instancia** de `ClapTrap`.

**DiamondTrap**:
```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;  // Oculta el nombre de ClapTrap
    
public:
    DiamondTrap(std::string name);
    using ScavTrap::attack;  // Usa attack() de ScavTrap
    void whoAmI();
};
```

**Atributos de DiamondTrap**:
- Hit Points: de `FragTrap` (100)
- Energy Points: de `ScavTrap` (50)
- Attack Damage: de `FragTrap` (30)
- `attack()`: de `ScavTrap`

**`using` directive**:
```cpp
using ScavTrap::attack;  // Resuelve ambigüedad: usa attack() de ScavTrap
```

**Constructores con herencia virtual**:
```cpp
DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"),  // Llama directamente al abuelo
      ScavTrap(name),
      FragTrap(name),
      name(name) {}
```

Con herencia virtual, la clase **más derivada** (DiamondTrap) debe inicializar `ClapTrap` explícitamente.

---

## 💡 Conceptos Clave {#conceptos-clave-cpp03}

### 1. Herencia

**Sintaxis**:
```cpp
class ClaseDerivada : public ClaseBase {
    // Hereda todos los miembros públicos y protegidos
};
```

**Tipos de herencia**:
- `public`: Lo más común. `public` permanece `public`, `protected` permanece `protected`
- `protected`: `public` se vuelve `protected`
- `private`: Todo se vuelve `private` (raramente usado)

**Regla general en 42**: Usar siempre `public`.

### 2. Modificadores de Acceso

| Modificador | Accesible desde clase derivada | Accesible desde fuera |
|-------------|--------------------------------|-----------------------|
| `public` | ✅ | ✅ |
| `protected` | ✅ | ❌ |
| `private` | ❌ | ❌ |

**`protected`**: Visible en clases derivadas pero no desde fuera.

```cpp
class ClapTrap {
protected:
    std::string name;  // Accesible en ScavTrap
private:
    int secretValue;   // No accesible en ScavTrap
};
```

### 3. Constructores y Destructores

**Orden de construcción**: Base → Derivada
**Orden de destrucción**: Derivada → Base

```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name) : ClapTrap(name) {
        // Constructor de ClapTrap se ejecuta PRIMERO
    }
    
    ~ScavTrap() {
        // Destructor de ScavTrap se ejecuta PRIMERO
        // Luego ~ClapTrap()
    }
};
```

**Initialization list**: Obligatorio para llamar al constructor del padre.

### 4. Sobrescritura de Métodos

```cpp
class ClapTrap {
public:
    void attack(const std::string& target);
};

class ScavTrap : public ClapTrap {
public:
    void attack(const std::string& target);  // Sobrescribe (shadow)
};

ScavTrap st("Robot");
st.attack("Enemy");  // Llama a ScavTrap::attack()
```

**No confundir con polimorfismo**: Sin `virtual`, no hay polimorfismo dinámico.

### 5. Herencia Múltiple

```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
    // Hereda de AMBOS
};
```

**Ambigüedades**:
```cpp
DiamondTrap dt("Diamond");
dt.attack("Enemy");  // ❌ Error: ambiguo (ScavTrap::attack o FragTrap::attack?)

// Solución 1: Especificar scope
dt.ScavTrap::attack("Enemy");

// Solución 2: using directive
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    using ScavTrap::attack;  // Usa esta versión por defecto
};
```

### 6. Herencia Virtual (Diamond Problem)

**Problema**:
```
       ClapTrap (name, HP, energy)
      /                    \
 ScavTrap                 FragTrap
      \                    /
           DiamondTrap
```

Sin `virtual`, `DiamondTrap` tiene **dos copias** de `ClapTrap` → ambigüedad y desperdicio.

**Solución**:
```cpp
class ScavTrap : virtual public ClapTrap {};
class FragTrap : virtual public ClapTrap {};
```

Ahora hay **una sola instancia** de `ClapTrap` compartida.

**Inicialización con herencia virtual**:
```cpp
// La clase MÁS DERIVADA debe inicializar la base virtual
DiamondTrap::DiamondTrap(std::string n) 
    : ClapTrap(n + "_clap_name"),  // Inicializa directamente
      ScavTrap(n),                  // Estos NO inicializan ClapTrap
      FragTrap(n) {}
```

### 7. `using` Directive

```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    using ScavTrap::attack;  // Resuelve ambigüedad
};
```

Hace que `attack()` de `ScavTrap` sea la versión por defecto en `DiamondTrap`.

---

## ✨ Resumen

| Ejercicio | Concepto |
|-----------|----------|
| ex00 | Clase base ClapTrap |
| ex01 | Herencia simple (ScavTrap), sobrescritura |
| ex02 | Otra derivada (FragTrap) |
| ex03 | Herencia múltiple, herencia virtual, Diamond Problem |

**Puntos clave**:
- Herencia `public` para mantener niveles de acceso
- `protected` para miembros accesibles en derivadas
- Constructores: inicializar base con initialization list
- Orden: construcción base→derivada, destrucción derivada→base
- Herencia virtual: resuelve Diamond Problem (una sola instancia base)
- `using`: resuelve ambigüedades en herencia múltiple

---

**Autor**: Laura Giner  
**Fecha**: Enero 2026  
**Proyecto**: 42 School - CPP Module 03

---
---

# CPP Module 04

<a name="cpp-module-04"></a>

## 🎯 Descripción General {#descripción-general-cpp04}

El **Módulo CPP_04** introduce el **polimorfismo** (polymorphism) en C++. Los temas principales son:
- Funciones virtuales (`virtual`)
- Destructores virtuales
- Polimorfismo dinámico (late binding)
- Clases abstractas (pure virtual functions)
- Deep copy vs shallow copy
- Interfaces en C++

**Estándar**: C++98

---

## 🚀 Ejercicios {#ejercicios-cpp04}

### ex00: Polymorphism - Animal, Cat, Dog

Introducción al polimorfismo con funciones virtuales.

**Clase base Animal**:
```cpp
class Animal {
protected:
    std::string type;
    
public:
    Animal();
    virtual ~Animal();  // ⭐ Destructor virtual
    
    virtual void makeSound() const;  // ⭐ Función virtual
    std::string getType() const;
};
```

**Clases derivadas**:
```cpp
class Dog : public Animal {
public:
    Dog();
    void makeSound() const;  // Sobrescribe (override)
};

class Cat : public Animal {
public:
    Cat();
    void makeSound() const;  // Sobrescribe
};
```

**Polimorfismo en acción**:
```cpp
const Animal* animal = new Dog();
animal->makeSound();  // ✅ "Woof!" (llama a Dog::makeSound)
delete animal;        // ✅ Llama a ~Dog() y luego ~Animal()

// Sin virtual:
animal->makeSound();  // ❌ Llama a Animal::makeSound (incorrecto)
delete animal;        // ❌ Solo llama a ~Animal() (memory leak)
```

**WrongAnimal (contraste sin virtual)**:
```cpp
class WrongAnimal {
public:
    void makeSound() const;  // ❌ NO virtual
    ~WrongAnimal();           // ❌ NO virtual
};

class WrongCat : public WrongAnimal {
public:
    void makeSound() const;  // Sobrescribe, pero sin polimorfismo
};

const WrongAnimal* wrong = new WrongCat();
wrong->makeSound();  // ❌ Llama a WrongAnimal::makeSound (tipo del puntero)
```

### ex01: Brain - Deep Copy

Añade un atributo `Brain*` a `Dog` y `Cat` para practicar deep copy.

**Clase Brain**:
```cpp
class Brain {
private:
    std::string ideas[100];  // Array de ideas
    
public:
    Brain();
    Brain(const Brain& other);            // Deep copy
    Brain& operator=(const Brain& other); // Deep copy
    ~Brain();
};
```

**Deep copy en Brain**:
```cpp
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];  // Copia cada string
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}
```

**Dog con Brain**:
```cpp
class Dog : public Animal {
private:
    Brain* brain;  // ⚠️ Puntero: necesita deep copy
    
public:
    Dog();
    Dog(const Dog& other);            // Deep copy del brain
    Dog& operator=(const Dog& other); // Deep copy del brain
    ~Dog();
};
```

**Implementación de deep copy en Dog**:
```cpp
Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain();  // Asigna memoria
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*other.brain);  // ✅ Copia el contenido
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);  // Llama al = del padre
        delete this->brain;        // Libera el viejo
        this->brain = new Brain(*other.brain);  // Copia el nuevo
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;  // Libera memoria
}
```

**Shallow vs Deep Copy**:
```cpp
// Shallow copy (MAL):
this->brain = other.brain;  // ❌ Ambos apuntan al mismo Brain

// Deep copy (BIEN):
this->brain = new Brain(*other.brain);  // ✅ Copia independiente
```

**Prueba de deep copy**:
```cpp
Dog dog1;
Dog dog2 = dog1;  // Deep copy

// Modificar dog2.brain NO afecta a dog1.brain (copias independientes)
```

### ex02: Abstract Classes

Convierte `Animal` en clase abstracta (no instanciable).

**Función virtual pura**:
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // ⭐ = 0 (pure virtual)
    virtual ~Animal();
};
```

**Clase abstracta**: Tiene al menos una función virtual pura (`= 0`).

**Consecuencias**:
```cpp
Animal animal;  // ❌ Error: no se puede instanciar clase abstracta

Dog dog;        // ✅ OK: Dog implementa makeSound()
Animal* ptr = new Dog();  // ✅ OK: puntero a clase abstracta
```

**Clase derivada debe implementar pure virtual**:
```cpp
class Dog : public Animal {
public:
    void makeSound() const;  // ✅ Implementa función pura
};
```

Si `Dog` NO implementa `makeSound()`, también es abstracta.

---

## 💡 Conceptos Clave {#conceptos-clave-cpp04}

### 1. Funciones Virtuales

**`virtual`**: Permite polimorfismo dinámico (late binding).

```cpp
class Base {
public:
    virtual void func();  // ⭐ Virtual
};

class Derived : public Base {
public:
    void func();  // Sobrescribe (override)
};

Base* ptr = new Derived();
ptr->func();  // ✅ Llama a Derived::func() (runtime)
```

**Sin `virtual`**:
```cpp
ptr->func();  // ❌ Llama a Base::func() (compile-time, tipo del puntero)
```

**Cuándo usar `virtual`**:
- Cuando esperas usar punteros/referencias a base para objetos derivados
- Funciones que serán sobrescritas en derivadas
- **Siempre** en destructores si hay herencia

### 2. Destructores Virtuales

**⚠️ Regla de oro**: Si una clase tiene funciones virtuales, el destructor **DEBE ser virtual**.

```cpp
class Animal {
public:
    virtual ~Animal();  // ⭐ Virtual
};

class Dog : public Animal {
private:
    Brain* brain;
public:
    ~Dog() { delete brain; }
};

Animal* animal = new Dog();
delete animal;  // ✅ Llama a ~Dog() → ~Animal() (correcto)
```

**Sin destructor virtual**:
```cpp
class Animal {
public:
    ~Animal();  // ❌ No virtual
};

Animal* animal = new Dog();
delete animal;  // ❌ Solo ~Animal() → brain NO se libera (memory leak)
```

### 3. Polimorfismo Dinámico

**Binding**:
- **Static binding** (compile-time): El compilador decide qué función llamar
- **Dynamic binding** (runtime): Tabla virtual decide en ejecución

**Virtual Table (vtable)**:
```
Animal*
  ↓
vtable:
  makeSound → Dog::makeSound
  destructor → Dog::~Dog
```

Cada objeto con funciones virtuales tiene un puntero a su vtable.

**Ventajas del polimorfismo**:
```cpp
void processAnimals(Animal** animals, int size) {
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();  // Llama a la versión correcta
}

Animal* animals[4];
animals[0] = new Dog();
animals[1] = new Cat();
animals[2] = new Dog();
animals[3] = new Cat();

processAnimals(animals, 4);  // Woof, Meow, Woof, Meow
```

### 4. Clases Abstractas

**Función virtual pura**:
```cpp
virtual void func() = 0;  // = 0 significa "pure virtual"
```

**Clase abstracta**:
- Tiene al menos una función virtual pura
- **NO se puede instanciar**
- Sirve como interfaz/contrato

**Ejemplo de interfaz**:
```cpp
class IAnimal {  // Interfaz (prefijo I opcional)
public:
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual ~IAnimal() {}
};

class Dog : public IAnimal {
public:
    void makeSound() const { /* ... */ }  // DEBE implementar
    void move() const { /* ... */ }        // DEBE implementar
};
```

**Ventaja**: Fuerza a las derivadas a implementar ciertas funciones.

### 5. Deep Copy vs Shallow Copy

**Shallow copy** (copia superficial):
```cpp
this->ptr = other.ptr;  // ❌ Ambos apuntan al mismo objeto
```

Problema: Si uno destruye el objeto, el otro tiene un dangling pointer.

**Deep copy** (copia profunda):
```cpp
this->ptr = new Type(*other.ptr);  // ✅ Copia independiente
```

**Cuándo es necesario deep copy**:
- La clase tiene punteros a memoria dinámica
- Regla de tres: Si necesitas destructor personalizado, probablemente necesitas constructor de copia y operador de asignación personalizados

**Patrón para deep copy**:
```cpp
ClassName::ClassName(const ClassName& other) {
    this->ptr = new Type(*other.ptr);  // Copia profunda
}

ClassName& ClassName::operator=(const ClassName& other) {
    if (this != &other) {
        delete this->ptr;              // Libera el viejo
        this->ptr = new Type(*other.ptr);  // Copia el nuevo
    }
    return *this;
}

ClassName::~ClassName() {
    delete this->ptr;  // Libera memoria
}
```

### 6. Arrays de Polimorfismo

```cpp
Animal* animals[10];
animals[0] = new Dog();
animals[1] = new Cat();

for (int i = 0; i < 2; i++) {
    animals[i]->makeSound();  // Polimorfismo
    delete animals[i];        // Destructor virtual importante
}
```

**⚠️ Importante**: Usar array de punteros (`Animal**` o `Animal*[]`), NO array de objetos (`Animal[]`), para polimorfismo.

### 7. `override` y `final` (C++11)

**⚠️ En C++98**: NO existen `override` ni `final`.

En C++11+:
```cpp
class Dog : public Animal {
public:
    void makeSound() const override;  // Marca explícitamente override
};
```

En C++98, omitir estas palabras clave.

---

## ✨ Resumen

| Ejercicio | Concepto |
|-----------|----------|
| ex00 | Funciones virtuales, polimorfismo, WrongAnimal (sin virtual) |
| ex01 | Deep copy con punteros (Brain), memoria dinámica |
| ex02 | Clases abstractas, funciones virtuales puras |

**Puntos clave**:
- `virtual`: Permite polimorfismo dinámico (runtime binding)
- Destructor virtual: **Obligatorio** si hay funciones virtuales
- `= 0`: Función virtual pura → clase abstracta (no instanciable)
- Deep copy: Copiar contenido de punteros, no solo direcciones
- Regla de tres: Destructor, constructor de copia, operador de asignación
- Polimorfismo: Punteros/referencias a base permiten usar derivadas

---

**Autor**: Laura Giner  
**Fecha**: Febrero 2026  
**Proyecto**: 42 School - CPP Module 04