/*
NIM : 43324039
Nama : Dionisius Sidabutar
Prodi : D3 Teknologi Komputer
*/

#ifndef _RedBlackTree_H
#define _RedBlackTree_H

typedef int ElementType;

struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;

RedBlackTree Insert(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
Position Find(ElementType X, RedBlackTree T);
Position FindMin (RedBlackTree T);
Position FindMax (RedBlackTree T);
RedBlackTree Initialize(RedBlackTree T);
RedBlackTree Delete(ElementType X, RedBlackTree T);
RedBlackTree MakeEmpty(RedBlackTree T);

Position LeftRotate (Position K2);
Position RightRotate(Position K1);
Position Rotate(ElementType X, Position T);

void HandleReorient(ElementType Item, RedBlackTree T);

void InOrder(RedBlackTree T);
void PreOrder(RedBlackTree T);
void PostOrder(RedBlackTree T);


#endif