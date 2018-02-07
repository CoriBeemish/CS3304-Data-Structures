//FILE: ComplexNumbers.h

#ifndef BEEMISH_COMPLEX_H
#define BEEMISH_COMPLEX_H

class complex{
	
	public:
		complex (int r = 0, int i = 1);
		  // preconditions: d is not 0
		  // postconditions: rational number has been created where
		  //                 rational number is stored in lowest
		  
		int get_real() const;
		// postcondition: numerator has been returned
	    int get_imag() const;
		// postcondition: denominator has been returned
		
	private:
		double real;
		double imag;
			// complex 
		
	
};

complex operator + (const complex& c1, const complex& c2);
	//PRECONDITION: 
	//POSTCONDITION: The sum of complex c1 & c2 are returned.  

complex operator - (const complex& c1, const complex& c2);
	//PRECONDITION:
	//POSTCONDITION: The difference of complex numbers c1 & c2 are returned.

complex operator / (const complex& c1, const complex& c2);
	//PRECONDITION: c2 is not zero. 
	//POSTCONDITION: 
	
complex operator * (const complex& c1, const complex& c2);
	//PRECONDITION:
	//POSTCONDITION: 
	
void complex::display()
{
	cout << real << " + " << imag << "i.";
}
#endif