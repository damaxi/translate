#translate
[![Build Status](https://travis-ci.org/damaxi/translate.svg?branch=master)](https://travis-ci.org/damaxi/translate)   
Qt translator library using translator using Google Translate, Bing Translator, Yandex.Translate etc;

### Short description
This is helper library for wordflow application. The library should translate given word using multiple engines for free. 
Exposing easy to use Qt API which consist of:
* Input parameters:
	* original word
	* source language
	* desired language
* Output parameters:
	* translated word
	* error flag

The user set up one of parameter then when all parameters are setted, the word is auto-translated. If there is connection error then auto-proxy set up next translate engine.
