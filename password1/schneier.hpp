/***********************************************
 *
 * Describes a Schneier password, generated using
 * pieces of each word from a sentence
 *
 * Author: swolewizard
 ***********************************************/
#ifndef SCHNEIER_HPP
#define SCHNEIER_HPP
#include "password.hpp" /* parent class */

class Schneier: public Password
{
  public:
	/* Prompts user for a sentence and creates a Schneier password using randomly selected pieces of it*/
	Schneier();
};

#endif
