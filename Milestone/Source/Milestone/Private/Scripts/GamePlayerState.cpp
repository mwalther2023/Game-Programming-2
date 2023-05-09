// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/GamePlayerState.h"

AGamePlayerState::AGamePlayerState()
{

}

void AGamePlayerState::ReachedEnd()
{
	SetIsSpectator(true);
}