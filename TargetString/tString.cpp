#include<iostream>
#include "tString.h"



tString::tString()
{
	str_ = nullptr;
	length_ = 0;
}

tString::tString( const char* str )
{
	length_ = strlen( str );

	this->str_ = new char [length_ + 1];

	for (size_t i = 0; i < length_; i++ ) {
		str_[i] = str[i];
	}

	str_[length_] = '\0';
}

tString::tString			 (  tString&& other ) noexcept
{
	this->length_ = other.length_;
	this->str_ = other.str_;
	other.str_ = nullptr;
}
tString::~tString()
{
	delete[]str_;
}

tString::tString			 ( const tString& other )
{
	length_ = strlen( other.str_ );

	this->str_ = new char[length_ + 1];

	for ( size_t i = 0; i < length_; i++ ) {
		this->str_[i] = other.str_[i];
	}

	this->str_[length_] = '\0';
}



tString& tString::operator =  ( const tString& other )
{
	this->length_ = strlen( other.str_ );

	this->str_ = new char [length_+1];

	for (size_t i = 0; i < length_; i++) {
		this->str_[i] = other.str_[i];
	}
	
	this->str_[length_] = '\0';

	return *this;
}

tString& tString::operator=( tString&& other) noexcept
{
	this->length_ = other.length_;
	this->str_=other.str_; 

	other.str_ = nullptr;
	return *this;
	
}

tString tString::operator +  ( const tString& other )
{
	if (other.str_ == nullptr || other.length_ == 0) {
		return *this;
	}

	tString newStr;

	newStr.str_ = new char[this->length_ + other.length_ + 1];
	newStr.length_ = this->length_ + other.length_;
	size_t i = 0;
	for (; i < this->length_; i++) {
		newStr.str_[i] = this->str_[i];
	}

	for (size_t j = 0; j < other.length_; j++, i++){
		newStr.str_[i] = other.str_[j];
	}


	newStr.str_[newStr.length_] = '\0';

	return newStr;
}

tString& tString::operator += ( const tString& other )  
{
	if (other.str_ == nullptr || other.length_ == 0) {
		return *this;
	}
	tString newStr;
	newStr.length_ = this->length_ + other.length_;
	newStr.str_ = new char[this->length_ + other.length_ + 1];

	size_t i = 0;
	for (; i < this->length_; i++){
		newStr.str_[i] = this->str_[i];
	}

	for (size_t j = 0; j < other.length_; j++, i++){
		newStr.str_[i] = other.str_[j];
	}

	
	newStr.str_[newStr.length_] = '\0';

	this->length_ = newStr.length_;
	this->str_ = newStr.str_;
	newStr.str_ = nullptr;
	return *this;
}

bool    tString::operator == ( const tString& other )
{
	if ( this->length_ != other.length_ )
	{ 
		return false;
	}

	for ( size_t i = 0; i < this->length_; i++ )
	{
		if ( this->str_[i] != other.str_[i] )
		{
			return false;
		}
	}
	return true;
}

bool    tString::operator != ( const tString& other )
{
	return !( this->operator == ( other ));
}

char&   tString::operator [] ( size_t index )
{
	return str_[index];
}

void    tString::print()
{
	std::cout << str_;
}



tString tString::resize      ( tString str, size_t new_size )
{
	return tString();
}
