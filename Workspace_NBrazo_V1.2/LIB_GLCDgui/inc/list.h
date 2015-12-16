/*
   ********************* Authors *********************
   ***** Laboratorio de Sistemas Embebidos (LSE) *****
   *****    http://laboratorios.fi.uba.ar/lse    *****
   ******************* 20/12/2011 ********************
     Ezequiel Espósito <ezequiel.esposito@gmail.com>
         Alan Kharsansky <akharsa@gmail.com>
       Federico Roasio <federoasio@gmail.com>
     Daniel Schermuk <daniel.schermuk@gmail.com>
   ***************************************************
*/

#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>

#ifndef NULL
#define NULL	0
#endif

struct TypeNode
{
	const char* name;
	void* data;
	struct TypeNode* next;
};
typedef struct TypeNode TNode;

struct TypeList
{
	TNode* first;
	TNode* last;
	uint16_t size;
};
typedef struct TypeList TList;

void List_Init (TList* pList);

void List_AddNode (TList* pList, const char* _name, void* _data);

TNode* List_SearchNode (TList* pList, const char* _name);

#endif /* LIST_H_ */
