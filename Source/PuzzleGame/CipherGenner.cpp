// Fill out your copyright notice in the Description page of Project Settings.

#include "CipherGenner.h"

CipherGenner::CipherGenner()
{
    Code = FMath::RandRange(1000, 9999);
}

CipherGenner::~CipherGenner()
{
}

int32 CipherGenner::GetCode(){
    return Code;
}
int32 CipherGenner::GetCodePart(int32 n){
    return Code%(10^(n-1));
}
