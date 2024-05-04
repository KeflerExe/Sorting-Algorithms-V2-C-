/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 5: Métodos de ordenación
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 05/04/2024
/// Archivo: main_sort.cc

#include <iostream>
#include <string>

#include "sortmethod.h"
#include "nif.h"

// Función que comprueba que el número de parámetros de entrada es correcto y proporciona ayuda al usuario
void Usage(int argc, char *argv[]) {
  if (argc != 9 && argc != 10) {
    std::cout << "--Ordenacion" << std::endl;
    std::cout << "Modo de uso: ./main_sort -size <s> -ord <m> -init <manual|file|random> <f> -trace <y|n>" << std::endl << "Pruebe ./hash_main --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }  
  if (argv[1] == "--help") {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Ordenacion" << std::endl;
      std::cout << "Modo de uso: ./main_sort -size <s> -ord <m> -init <manual|file|random> <f> -trace <y|n>" << std::endl;
      std::cout << "-size <s>: indica el tamaño de la secuencia" << std::endl;
      std::cout << "-ord <f>: es el código que identifica al método de ordenación. Puede ser: selection, quick, heap, shell, radix" << std::endl;
      std::cout << "-init <manual|file|random>: indica la forma de iniciar la secuencia. De forma manual por el usuario, con un archivo que contenga los valores o de forma aleatoria" << std::endl;
      std::cout << "-trace <s>: indica si se muestra o no la traza durante la ejecución" << std::endl;
      exit(EXIT_SUCCESS);
    } 
  }
}

// Función principal
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int size = 0;
  std::string ord;
  std::string init;
  std::string filename;
  bool traza = false;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-size") {
      if (i + 1 < argc) {
        size = std::stoi(argv[i + 1]);
        i++;
      }
    } else if (arg == "-ord") {
      if (i + 1 < argc) {
        ord = argv[i + 1];
        i++;
      }
    } else if (arg == "-init") {
      if (i + 1 < argc) {
        init = argv[i + 1];
        i++;
      }
      if (i + 1 < argc && init == "file") {
        filename = argv[i + 1];
        i++;
      }
    } else if (arg == "-trace") {
      if (i + 1 < argc) {
        std::string traceArg = argv[i + 1];
        if (traceArg == "y") {
          traza = true;
        }
        i++;
      }
    }
  }
  if (ord == "selection") { // SelectionSort
    SelectionSort<Nif> selection_sort(size, traza);
    if (init == "random") {
      for (int i = 0; i < size; i++) {
        selection_sort.insert(Nif());
      }
    } else if (init == "manual") {
      for (int i = 0; i < size; i++) {
        long nif;
        std::cout << "Introduzca un NIF: ";
        std::cin >> nif;
        selection_sort.insert(Nif(nif));
      }
    } else if (init == "file") {
      selection_sort.read(filename);
    }
    selection_sort.print();
    selection_sort.sort();
    selection_sort.print();
  } else if (ord == "quick") { // QuickSort
    QuickSort<Nif> quick_sort(size);
    if (init == "random") {
      for (int i = 0; i < size; i++) {
        quick_sort.insert(Nif());
      }
    } else if (init == "manual") {
      for (int i = 0; i < size; i++) {
        long nif;
        std::cout << "Introduzca un NIF: ";
        std::cin >> nif;
        quick_sort.insert(Nif(nif));
      }
    } else if (init == "file") {
      quick_sort.read(filename);
    }
    quick_sort.print();
    quick_sort.sort();
    quick_sort.print();
  } else if (ord == "heap") { // HeapSort
    HeapSort<Nif> heap_sort(size, traza);
    if (init == "random") {
      for (int i = 0; i < size; i++) {
        heap_sort.insert(Nif());
      }
    } else if (init == "manual") {
      for (int i = 0; i < size; i++) {
        long nif;
        std::cout << "Introduzca un NIF: ";
        std::cin >> nif;
        heap_sort.insert(Nif(nif));
      }
    } else if (init == "file") {
      heap_sort.read(filename);
    }
    heap_sort.print();
    heap_sort.sort();
    heap_sort.print();
  } else if (ord == "shell") { // ShellSort
    std::cout << "Introduzca el valor de alfa: ";
    double alfa;
    std::cin >> alfa;
    if (alfa <= 0 || alfa >= 1) {
      std::cerr << "Error: el valor de alfa debe estar entre 0 y 1." << std::endl;
      exit(EXIT_FAILURE);
    }
    ShellSort<Nif> shell_sort(size, alfa, traza);
    if (init == "random") {
      for (int i = 0; i < size; i++) {
        shell_sort.insert(Nif());
      }
    } else if (init == "manual") {
      for (int i = 0; i < size; i++) {
        long nif;
        std::cout << "Introduzca un NIF: ";
        std::cin >> nif;
        shell_sort.insert(Nif(nif));
      }
    } else if (init == "file") {
      shell_sort.read(filename);
    }
    shell_sort.print();
    shell_sort.sort();
    shell_sort.print();
  } else if (ord == "radix") { // RadixSort
    RadixSort<Nif> radix_sort(size, traza);
    if (init == "random") {
      for (int i = 0; i < size; i++) {
        radix_sort.insert(Nif());
      }
    } else if (init == "manual") {
      for (int i = 0; i < size; i++) {
        long nif;
        std::cout << "Introduzca un NIF: ";
        std::cin >> nif;
        radix_sort.insert(Nif(nif));
      }
    } else if (init == "file") {
      radix_sort.read(filename);
    }
    radix_sort.print();
    radix_sort.sort();
    radix_sort.print();
  }
  return 0;
}