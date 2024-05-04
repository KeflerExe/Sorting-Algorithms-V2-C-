/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 5: Métodos de ordenación
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 05/04/2024
/// Archivo: 

#include <iostream>
#include <vector>

#include "sequence.h"

// Función de ordenación por selección
template<typename Key>
void selectionSort(staticSequence<Key>& sequence, size_t size, bool traza) {
  for (int i = 0; i < size - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < size; ++j) {
      if (sequence[j] < sequence[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      Key temp = sequence[i];
      sequence.setvalue(i, sequence[minIndex]);
      sequence.setvalue(minIndex, temp);
    }
    if (traza) {
      sequence.print();
    }
  }
}

// Función de partición para QuickSort
template<typename Key>
int partition(staticSequence<Key>& sequence, int low, int high) {
  Key pivot = sequence[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (sequence[j] <= pivot) {
      i++;
      Key temp = sequence[i];
      sequence.setvalue(i, sequence[j]);
      sequence.setvalue(j, temp);
    }
  }
  Key temp = sequence[i + 1];
  sequence.setvalue(i + 1, sequence[high]);
  sequence.setvalue(high, temp);
  return i + 1;
}

// Función QuickSort
template<typename Key>
void quickSort(staticSequence<Key>& sequence, int low, int high) {
  if (low < high) {
    int pi = partition(sequence, low, high);
    quickSort(sequence, low, pi - 1);
    quickSort(sequence, pi + 1, high);
  }
}

// Función de conveniencia para llamar a QuickSort
template<typename Key>
void quickSort(staticSequence<Key>& sequence, size_t size) {
  quickSort(sequence, 0, size - 1);
}

// Función para amontonar en HeapSort
template<typename Key>
void Amontonar(staticSequence<Key>& sequence, size_t size, int i) {
  int largest = i;
  int left = 2 * i + 1; 
  int right = 2 * i + 2; 
  if (left < size && sequence[left] > sequence[largest]) {
    largest = left;
  }
  if (right < size && sequence[right] > sequence[largest]) {
    largest = right;
  }
  if (largest != i) {
    sequence.swap(i, largest);
    Amontonar(sequence, size, largest);
  }
}

// Función de ordenación por montículos
template<typename Key>
void heapSort(staticSequence<Key>& sequence, size_t size, bool traza) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    Amontonar(sequence, size, i);
  }
  for (int i = size - 1; i > 0; i--) {
    sequence.swap(0, i);
    if (traza) {
      sequence.print();
    }
    Amontonar(sequence, i, 0);
  }
}

// Función de ordenación por shellsort con alfa
template<typename Key>
void shellSort(staticSequence<Key>& sequence, size_t size, double alfa, bool traza) {
  for (int gap = size * alfa; gap > 0; gap *= alfa) {
    for (int i = gap; i < size; i += 1) {
      Key temp = sequence[i];
      int j;
      for (j = i; j >= gap && sequence[j - gap] > temp; j -= gap) {
        sequence.setvalue(j, sequence[j - gap]);
      }
      sequence.setvalue(j, temp);
      if (traza) {
        sequence.print();
      }
    }
  }
}

// Función de ordenación por radixsort
template<typename Key>
void radixSort(staticSequence<Key>& sequence, size_t size, bool traza) {
  Key maxKey = sequence[0];
  for (int i = 1; i < sequence.size(); i++) {
    if (sequence[i] > maxKey) {
      maxKey = sequence[i];
    }
  }
  for (int exp = 1; maxKey / exp > 0; exp *= 10) {
    std::vector<Key> output(sequence.size());
    int count[10] = {0};
    for (int i = 0; i < sequence.size(); i++) {
      count[(sequence[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = sequence.size() - 1; i >= 0; i--) {
      output[count[(sequence[i] / exp) % 10] - 1] = sequence[i];
      count[(sequence[i] / exp) % 10]--;
    }
    for (int i = 0; i < sequence.size(); i++) {
      sequence.setvalue(i, output[i]);
    }
    if (traza) {
      sequence.print();
    }
  }
}