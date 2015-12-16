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

#include <string.h>
#include "list.h"

void List_Init (TList* pList)
{
	pList->first = NULL;
	pList->last = NULL;
	pList->size = 0;
}

void List_AddNode (TList* pList, const char* _name, void* _data)
{
	TNode* auxPointerNode;

	auxPointerNode = (TNode*) GUI_Malloc ( sizeof(TNode) );

	auxPointerNode->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxPointerNode->name, _name, 12);
	auxPointerNode->data = _data;

	if (pList->first == NULL && pList->last == NULL)
	{
		pList->first = auxPointerNode;
		pList->last = auxPointerNode;
	}
	else
	{
		pList->last->next = auxPointerNode;
		pList->last = auxPointerNode;
	}
}

TNode* List_SearchNode (TList* pList, const char* _name)
{
	TNode* auxPNode = pList->first;
	while ( auxPNode != NULL && strncmp (auxPNode->name, _name, 12) != 0 )
	{
		auxPNode = auxPNode->next;
	}
	return auxPNode;

}

