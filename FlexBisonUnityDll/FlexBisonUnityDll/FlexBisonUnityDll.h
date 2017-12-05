#pragma once
#include <thread>
#include <mutex>
#include <queue>
#include <fstream>
#include <chrono>
#include <string>
#include <iostream>

extern "C"
{

	typedef struct String
	{
		char* str;
		size_t len;
	}FlexString, BisonString;

	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl BisonExecution();
	 *
	 * \brief	Esta es la funcion principal de ejecución del intepretador, no se va a llamar en
	 *			unity pues se llama internamente al inicializarla.
	 *
	 *
	 **************************************************************************************************/
	_declspec(dllexport) void __cdecl BisonExecution();
	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) BisonString __cdecl GetBisonString();
	 *
	 * \brief	Regresa el BisonString mas antiguo que se encuentre en el queue de strings. Se espera
	 *			a que el queue tenga al menos un dato dentro de el para regresar datos, pero se
	 *			ejecuta en un thread diferente al principal y al de bison.
	 *
	 * \return	Asegurado que va a regresar un BisonString.
	 **************************************************************************************************/
	_declspec(dllexport) BisonString __cdecl GetBisonString();
	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl BisonOut(std::string out);
	 *
	 * \brief	Para usarse dentro de los archivos de bison y flex, toma el output que le den
	 *			y lo agrega al queue de salida para GetBisonString();
	 *
	 * \param [in]	out 	El string que se vaya a meter al queue.
	 *
	 **************************************************************************************************/
	_declspec(dllexport) void __cdecl BisonOut(std::string out);
	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl PushBisonString(char* str, const size_t& len);
	 *
	 * \brief	Mete un string de cualquier lado al analizador de bison, es la unica interfaz
	 *			de entrada para la api. Se le van a agregar un '\n' y  2 '\0' al final del string.
	 *			Esto es por especificación de lex.
	 *
	 * \param [in]	str		El string que vaya a meterse.
	 * \param [in]	len		El tamaño del string.
	 *
	 **************************************************************************************************/
	_declspec(dllexport) void __cdecl PushBisonString(char* str, size_t len);
	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl StartBison();
	 *
	 * \brief	Esta funcion inicia el parser lexico con su thread, es importante que se llame al
	 *			inicio o todo lo que se llame subsecuentemente va a tirar null.
	 *
	 **************************************************************************************************/
	_declspec(dllexport) void __cdecl StartBison();
	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl TerminateBison();
	 *
	 * \brief	Llamar a esta funcion para terminar el interpretador, es importante llamarla para
	 *			evitar memory leaks.
	 *
	 **************************************************************************************************/
	_declspec(dllexport) void __cdecl TerminateBison();

	/**********************************************************************************************//**
	 * \fn	_declspec(dllexport) void __cdecl TerminateBison();
	 *
	 * \brief	En vista de que unity es una mamada, solo es necesario llamar esta funcion para evitar el
	 *			debraye de threading. Inmediatamente abre bison, le pasa el string, lo parsea y lo regresa.
	 *
	 * \return	Puede regresar un BisonString vacio si el resultado del parsing fallo, de otra forma
	 *			regresa el resultado esperado.
	 *
	 **************************************************************************************************/
	_declspec(dllexport) BisonString __cdecl BisonAllExecution(char* str, size_t len);
};