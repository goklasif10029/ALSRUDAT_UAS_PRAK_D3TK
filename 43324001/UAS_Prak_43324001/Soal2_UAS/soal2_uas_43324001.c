#include <stdio.h>
#include <stdlib.h>
#include "Fatal.h"
#include "soal1_uas_43324001.h"

typedef enum ColorType {sRed, Black
            } ColorType;

struct RedBlackNode{
    ElementType Element;
    ColorType Color;
    RedBlackTree Left;
    RedBlackTree Right;
    RedBlackTree Parent;
};

RedBlackTree MakeEmpty(RedBlackTree T){
    if(T != NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

RedBlackTree Insert(ElementType X, RedBlackTree T){
    if (T == NULL){
        T = malloc(sizeof(struct RedBlackNode));
        if(T == NULL)
            FatalError( "Out of space!");
        else{
            T->Element = X;
            T-> Left = NULL;
            T->Right = NULL;
            T->Color = Black;
        }
    }else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);

    return T;
}

Position X, P, GP, GGP;

void HandleReorient(ElementType Item, RedBlackTree T) {
    X->Color = sRed; 
    X->Left->Color = Black;
    X->Right->Color = Black;
 
    if (P->Color == sRed){  
        GP->Color = sRed;
        if ((Item < GP->Element) != (Item < P->Element))
            P = Rotate(Item, GP); 
        X = Rotate(Item, GGP);
        X->Color = Black;
    }
    T->Right->Color = Black; 
} 

ElementType Retrieve(Position P){
    return (P->Element);
}

Position Find(ElementType X, RedBlackTree T){
    if (T == NULL)
        return NULL;
    if( X < T->Element)
        return Find (X, T->Left);
    else if(X > T->Element)
        return Find (X, T->Right);
    else 
        return T; 
}

Position FindMin (RedBlackTree T){
    if (T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else   
        return FindMin(T->Left);
}
Position FindMax (RedBlackTree T){
    if (T != NULL)
        while(T->Right != NULL)
            T = T->Right;

        return T;
}

Position LeftRotate(Position K2) {
    Position K1;
 
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
 
    return K1; 
}

Position RightRotate(Position K1) {
    Position K2;
 
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
 
    return K2;
}

Position Rotate(ElementType X, Position Parent) {
    
    if (X < Parent->Element)
        return Parent->Left = X < Parent->Left->Element ?
            LeftRotate(Parent->Left) :
            RightRotate(Parent->Left);
    else
         return Parent->Right = X < Parent->Right->Element ?
            LeftRotate(Parent->Right) :
            RightRotate(Parent->Right);

}

void InOrder(RedBlackTree T){
	if(T != NULL){
		InOrder(T->Left);
		printf("%d ", T->Element);
		InOrder(T->Right);
	}
}

void PreOrder(RedBlackTree T){
	if(T != NULL){
		printf("%d ", T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}

void PostOrder(RedBlackTree T){
	if(T != NULL){
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%d ", T->Element);
	}
}
