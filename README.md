---
title: Labor 3
---

# CMake und CTest in der Softwareentwicklung

## Einführung in CMake und CTest

CMake ist ein plattformübergreifendes Build-System, das den Prozess der Kompilierung, Verlinkung und Installation von Software unabhängig vom Betriebssystem und der verwendeten Compiler-Toolchain automatisiert. CTest ist ein Teil der CMake-Suite und ermöglicht die automatisierte Durchführung von Tests.

**Vorteile von CMake:**

- Plattformunabhängiges Build-System für C, C++ und andere Sprachen
- Unterstützung verschiedener Compiler und Entwicklungsumgebungen
- Einfache Konfiguration von Bibliotheken und Abhängigkeiten
- Skalierbar für kleine bis sehr große Projekte
- Breite Verwendung in Open-Source-Projekten und der Industrie

**Vorteile von CTest:**

- Nahtlose Integration in den CMake-Workflow
- Automatisierte Testausführung und -berichterstattung
- Kann mit verschiedenen Testframeworks zusammenarbeiten
- Unterstützt parallele Testausführung
- Ermöglicht kontinuierliche Integration (CI)

## Ziel dieser Übung

In dieser Laborübung werden Sie ein kleines C-Projekt mit CMake aufsetzen und mit CTest automatisierte Tests erstellen. Sie lernen dabei:

1. Eine `CMakeLists.txt`-Datei zu erstellen
2. Ein Projekt mit mehreren Dateien zu kompilieren
3. Unit-Tests ohne externe Testbibliotheken zu implementieren
4. Die Tests mit CTest zu automatisieren

## Vorbereitung

Laden Sie die Ausgangsdateien von Github herunter:

```console
$ git clone https://github.com/bladewing/infosec-uebungen-cmake.git cmake
```

## Projektstruktur

Ihre Projektstruktur sollte folgendermaßen aussehen:

```
cmake_project/
├── src/
│   ├── calculator.c
│   ├── calculator.h
│   └── main.c
├── tests/
│   ├── test_calculator_add.c
│   └── test_calculator_multiply.c
└── Vagrantfile
└── CMakeLists.txt  (zu erstellen)
```

### Die Komponenten Ihres Projekts

1. `calculator.h` und `calculator.c` enthalten einfache Funktionen für grundlegende mathematische Operationen.
2. `main.c` ist der Einstiegspunkt der Anwendung und demonstriert die Verwendung der Taschenrechner-Funktionen.
3. Die Dateien im `tests/`-Verzeichnis enthalten einfache Tests für die mathematischen Funktionen.

## Aufgaben

### 1. Vagrant-VM starten

Starten Sie die Vagrant-VM mit dem folgenden Befehl:

```console
$ vagrant up
```

### 2. In die VM einloggen

Loggen Sie sich in die VM ein:

```console
$ vagrant ssh
```

### 3. Ins Projektverzeichnis wechseln

Wechseln Sie in das auf der virtuellen Maschine eingebundene Projektverzeichnis:

```console
$ cd /vagrant/
```

### 4. CMakeLists.txt erstellen

Erstellen Sie im Hauptverzeichnis des Projekts eine `CMakeLists.txt`-Datei mit folgendem Inhalt:

```cmake
# Mindestversion von CMake festlegen
cmake_minimum_required(VERSION 3.10)

# Projektname und Sprache festlegen
project(CalculatorProject VERSION 1.0 LANGUAGES C)

# C-Standard festlegen
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Quellcode-Dateien für die Hauptanwendung
set(SOURCES src/main.c src/calculator.c)

# Hauptprogramm erstellen
add_executable(calculator ${SOURCES})

# Tests aktivieren
enable_testing()

# Test für die Addition erstellen
add_executable(test_calculator_add tests/test_calculator_add.c src/calculator.c)
add_test(NAME TestAdd COMMAND test_calculator_add)

# Test für die Multiplikation erstellen
add_executable(test_calculator_multiply tests/test_calculator_multiply.c src/calculator.c)
add_test(NAME TestMultiply COMMAND test_calculator_multiply)
```

### 5. Build-Verzeichnis erstellen und CMake ausführen

Nun erstellen Sie ein Build-Verzeichnis und führen CMake aus:

```console
$ mkdir build
$ cd build
$ cmake ..
```

### 6. Kompilieren Sie das Projekt

```console
$ make
```

### 7. Führen Sie die Tests mit CTest aus

```console
$ ctest
```

Sie sollten eine Ausgabe erhalten, die anzeigt, dass alle Tests erfolgreich durchgeführt wurden.

### 8. Führen Sie das Hauptprogramm aus

```console
$ ./calculator
```

## Erweiterungsaufgaben

### 1. Zusätzliche Funktionen und Tests

Erweitern Sie die Berechnungsfunktionen um eine Funktion zur Division (`divide`) und implementieren Sie einen Test für diese Funktion in einer neuen Datei `tests/test_calculator_divide.c`. Passen Sie die `CMakeLists.txt` entsprechend an.

### 2. Test für Fehlerbehandlung

Implementieren Sie eine Fehlerbehandlung für die Division durch Null und schreiben Sie einen Test, der überprüft, ob die Fehlerbehandlung korrekt funktioniert.

### 3. Code Coverage Integration

Integrieren Sie ein Code-Coverage-Tool in Ihr CMake-Setup, um zu überprüfen, wie gut Ihre Tests den Code abdecken:

```cmake
# Zur CMakeLists.txt hinzufügen
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
endif()
```

Installieren Sie das Coverage-Tool und führen Sie es nach den Tests aus:

```console
$ sudo apt-get install lcov
$ make
$ ctest
$ lcov --capture --directory . --output-file coverage.info
$ genhtml coverage.info --output-directory coverage_report
$ firefox coverage_report/index.html  # oder einen anderen Browser
```

**Hinweis:** Wenn Sie in der VM arbeiten, müssen Sie die Datei über `/vagrant` nach auf das Hostsystem übertragen.
