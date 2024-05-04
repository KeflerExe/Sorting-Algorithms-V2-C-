/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 5: Métodos de ordenación
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 05/04/2024
/// Archivo: sequence.h

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>
#include <vector>

template<class Key>
class Sequence {
 public:
  virtual Key operator[](const int posicion) const = 0;
};

// Clase que implementa una secuencia estática
template<class Key>
class staticSequence : public Sequence<Key> {
 public:
  // Constructores
  staticSequence() {}
  staticSequence(unsigned size) { sequencia_.resize(size, 0); }

  // Destructor
  virtual ~staticSequence();

  // Métodos
  Key operator[](const int posicion) const override;
  void setvalue(const int posicion, const Key& key) { sequencia_[posicion] = key; }
  void insert(const Key& key);
  void read_file(const std::string& file_name);
  int size() const { return sequencia_.size(); }
  void resize(int size) { sequencia_.resize(size, 0); }
  void print();
  void swap(int i, int j);
 private:
  std::vector<Key> sequencia_;
};

// Destructor
template<class Key>
staticSequence<Key>::~staticSequence() {
  sequencia_.clear();
}

// Sobrecarga del operador []
template<class Key>
Key staticSequence<Key>::operator[](const int posicion) const {
  return sequencia_[posicion];
}

// Método que inserta un elemento en la secuencia
template<class Key>
void staticSequence<Key>::insert(const Key& key) {
  for (int i = 0; i < sequencia_.size(); i++) {
    if (sequencia_[i] == 0) {
      sequencia_[i] = key;
      return;
    }
  }
}

// Método que lee un archivo e inserta los datos en la secuencia
template<class Key>
void staticSequence<Key>::read_file(const std::string& file_name) {
  std::ifstream file(file_name);
  std::string key_str;
  while (std::getline(file, key_str)) {
    long int key = std::stol(key_str);
    insert(key);
  }
  file.close();
}

// Método que imprime la secuencia
template<class Key>
void staticSequence<Key>::print() {
  for (int i = 0; i < sequencia_.size(); i++) {
    std::cout << sequencia_[i] << " ";
  }
  std::cout << std::endl;
}

// Método que intercambia dos elementos de la secuencia
template<class Key>
void staticSequence<Key>::swap(int i, int j) {
  Key temp = sequencia_[i];
  sequencia_[i] = sequencia_[j];
  sequencia_[j] = temp;
}

#endif