/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 5: Métodos de ordenación
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 05/04/2024
/// Archivo: sortmethod.h

#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include <iostream>

#include "sequence.h"
#include "sort.cc"

template<class Key>
class SortMethod {
 public:
  virtual void sort() = 0;
 protected:
  staticSequence<Key> sequence_;
};

template<class Key>
class SelectionSort : public SortMethod<Key> {
 public:
  // Constructores
  SelectionSort() {}
  SelectionSort(unsigned size, bool traza) {
    sequence_.resize(size);
    traza_ = traza;
  }
  
  // Métodos
  void sort() {
    selectionSort(sequence_, sequence_.size(), traza_);
  }
  void insert(const Key& key) {
    sequence_.insert(key);
  }
  void read(const std::string& filename) {
    sequence_.read_file(filename);
  }
  void print() {
    sequence_.print();
  }
 private:
  staticSequence<Key> sequence_;
  bool traza_;
};

template<class Key>
class QuickSort : public SortMethod<Key> {
 public:
  // Constructores
  QuickSort() {}
  QuickSort(unsigned size) {
    sequence_.resize(size);
  }

  // Métodos
  void sort() {
    quickSort(sequence_, sequence_.size());
  }
  void insert(const Key& key) {
    sequence_.insert(key);
  }
  void read(const std::string& filename) {
    sequence_.read_file(filename);
  }
  void print() {
    sequence_.print();
  }
 private:
  staticSequence<Key> sequence_;
};

template<class Key>
class HeapSort : public SortMethod<Key> {
 public:
  // Constructores
  HeapSort() {}
  HeapSort(unsigned size, bool traza) {
    sequence_.resize(size);
    traza_ = traza;
  }
    
  // Métodos
  void sort() {
    heapSort(sequence_, sequence_.size(), traza_);
  }
  void insert(const Key& key) {
    sequence_.insert(key);
  }
  void read(const std::string& filename) {
    sequence_.read_file(filename);
  }
  void print() {
    sequence_.print();
  }
 private:
  staticSequence<Key> sequence_;
  bool traza_;
};

template<class Key>
class ShellSort : public SortMethod<Key> {
 public:
  // Constructores
  ShellSort() {}
  ShellSort(unsigned size, double alfa, bool traza) {
    sequence_.resize(size);
    alfa_ = alfa;
    traza_ = traza;
  }
    
  // Métodos
  void sort() {
    shellSort(sequence_, sequence_.size(), alfa_, traza_);
  }
  void insert(const Key& key) {
    sequence_.insert(key);
  }
  void read(const std::string& filename) {
    sequence_.read_file(filename);
  }
  void print() {
    sequence_.print();
  }
 private:
  staticSequence<Key> sequence_;
  bool traza_;
  double alfa_;
};

template<class Key>
class RadixSort : public SortMethod<Key> {
 public:
  // Constructores
  RadixSort() {}
  RadixSort(unsigned size, bool traza) {
    sequence_.resize(size);
    traza_ = traza;
  }
        
  // Métodos
  void sort() {
    radixSort(sequence_, sequence_.size(), traza_);
  }
  void insert(const Key& key) {
    sequence_.insert(key);
  }
  void read(const std::string& filename) {
    sequence_.read_file(filename);
  }
  void print() {
    sequence_.print();
  }
 private:
  staticSequence<Key> sequence_;
  bool traza_;
};

#endif