#include "tString.h"



tString::tString  ()
{
	str_ = nullptr;
	length_ = 0;
}
tString::tString  ( const char* str )
{
	length_ = strlen( str );

	this->str_ = new char [length_ + 1];

	for (size_t i = 0; i < length_; i++ ) {
		str_[i] = str[i];
	}

	str_[length_] = '\0';
}
tString::tString  ( const tString& other )
{
	length_ = strlen( other.str_ );

	this->str_ = new char[length_ + 1];

	for ( size_t i = 0; i < length_; i++ ) {
		this->str_[i] = other.str_[i];
	}

	this->str_[length_] = '\0';
}
tString::tString  ( tString&& other ) noexcept
{
	this->length_ = other.length_;
	this->str_ = other.str_;
	other.str_ = nullptr;
}

tString::~tString ()
{
	delete[]str_;
}

tString& tString::operator=  ( const tString& other )
{
	this->length_ = strlen(other.str_);

	this->str_ = new char [length_+1];

	for (size_t i = 0; i < length_; i++) {
		this->str_[i] = other.str_[i];
	}
	
	this->str_[length_] = '\0';

	return *this;
}
tString& tString::operator=  ( const char ch)
{
	tString temp(&ch);

	this->length_ = 1;

	this->str_ = new char[length_ + 1];

	for (size_t i = 0; i < length_; i++) {
		this->str_[i] = temp.str_[i];
	}

	this->str_[length_] = '\0';

	return *this;
	
}

tString& tString::operator=	 ( tString&& other ) noexcept
{
	this->length_ = other.length_;
	this->str_=other.str_; 

	other.str_ = nullptr;
	return *this;
	
}

tString  tString::operator+  ( const tString& other )
{
	tString result(*this);

	return result +=other;
}
tString  tString::operator+	 (const char ch )
{
	tString result(*this);
	
	return result += ch;
}

tString& tString::operator+= ( const tString& other )  
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
tString& tString::operator+= (const char ch )
{
	tString other(&ch);
	other.length_ = 1;
	
	return *this += other;
}
 
bool     tString::operator== ( const tString& other )
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
bool     tString::operator!= ( const tString& other )
{
	return !( this->operator == ( other ));
}

char&    tString::operator[] ( size_t index )
{
	return str_[index];
}

size_t   tString::get_len()
{
	return length_;
}
char*	 tString::get_str()
{
	return str_;
}

std::ostream& operator<< ( std::ostream& os, const tString& str )
{
	os << str.str_;
	return os;
}
std::istream& operator>> ( std::istream& is,  tString& str )
{	
	char other[255];
	std::cin >> other;

	str = other;
	return is;
}
