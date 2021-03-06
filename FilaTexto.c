
#include <stdio.h>
#include <stdlib.h>
#include "FilaTexto.h"

// incremento circular
int inc(int valor) {
  return (valor+1) % TAM;
}

FilaTexto * criar_fila() {
  FilaTexto *f = malloc(sizeof(FilaTexto));

  if (f == NULL) {
    return NULL;
  }

  f->ini = f->fim = 0;
  f->qt = 0;

  return f;
}

void destruir_fila(FilaTexto *f) {
  free(f);
}

int inserir_fila(FilaTexto *f, char *texto) {
  int fim = f->fim;

  if (fila_cheia(f)) {
    return -1;
  }


  f->v[fim] = texto;
  f->fim = inc(f->fim);
  f->qt++;

  return 0;
}

char *remover_fila(FilaTexto *f) {
  int ini = f->ini;
  char *result;

  if (fila_vazia(f)) {
    return NULL;
  }

  // primeiro elemento da fila
  result = f->v[ini];
  f->ini = inc(f->ini);
  f->qt--;

  return result;
}

int fila_vazia(FilaTexto *f) {
  if (f->qt == 0) {
    return TRUE;
  }

  return FALSE;
}

int fila_cheia(FilaTexto *f) {
  if (f->qt == TAM) {
    return TRUE;
  }

  return FALSE;
}

void imprimir_fila(FilaTexto *f) {
  int pos = f->ini;
  int i;
  printf("ini [ ");

  for (i = 0; i < f->qt; i++) {
    printf(" (%s) ", f->v[pos]);

    pos = inc(pos);
  }

  printf(" ] fim\n");
}
