// Fill out your copyright notice in the Description page of Project Settings.


#include "BPLib.h"


// const-correctness
FVector UBPLib::MoveTowards(const FVector& startPos, const FVector& endPos, float maxDist)
{
	FVector out;
	FVector direction = endPos - startPos;
	float posDist = direction.Length();
	direction.Normalize();
	
	if (posDist > maxDist)
	{
		//UE_LOG(LogTemp, Warning, TEXT("A %f"), maxDist);
		out = startPos + direction*maxDist;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("B"));

		out = endPos;
	}

	return out;


}
bool UBPLib::ToggleMovement(bool isMoving)
{
	if(isMoving)
	{
		//Stop moving

	}
	else 
	{
		//Start moving

	}
	return !isMoving;
}
