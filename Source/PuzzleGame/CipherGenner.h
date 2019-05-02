// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PUZZLEGAME_API CipherGenner
{
public:
	CipherGenner();
	~CipherGenner();
    //currently the code is set to 4 parts
    int32 GetCode();
    int32 GetCodePart(int32 n);
    //LookIntoFTexture2d
    //int** GetImage();
    //int** GetImagePart(int32 n);
private:
    int32 Code;
    //int** POIDH;
};
