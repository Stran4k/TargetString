
class tString
{
private:
  char*  str_;
  size_t length_;

public:

	tString();
	tString				(const char* str);
	tString				( tString&& other ) noexcept;

   ~tString();

	tString				( const tString& other );
	
	
	tString& operator =  ( const tString& other );
	tString& operator =	(  tString&& other ) noexcept;
	tString operator +  ( const tString& other );
	tString& operator += ( const tString& other );

	bool	operator ==	( const tString& other );
	bool	operator !=	( const tString& other );
	
	char&	operator []	( const size_t index );

	tString resize		( const tString str, const size_t new_size );
	
	void	print();
	


	

};
