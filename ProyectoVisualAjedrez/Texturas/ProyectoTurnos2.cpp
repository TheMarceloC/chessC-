#include <iostream>
#include <iostream>
#include <iostream>
using namespace std;

int fo,co,fd,cd, turno; // coordenadas numéricas dentro del tablero
string pieza,coord,piezad; // la pieza que vamos a mover y la coordenada
bool despejado=true;


void Coordenadas (string a,int b)
    {
        a [0]=toupper (a [0]); // Pasamos la letra a mayúscula  
        
        if (a.length() == 2){//-----------------------------------------------
            
            if (b==0){ // coordenadas origen
                
                switch (a [0]){
                case 'A':
                co=0;
                break;
                
                case 'B':
                co=1;
                break;
                
                case 'C':
                co=2;
                break;
                
                case 'D':
                co=3;
                break;
                
                case 'E':
                co=4;
                break;
                
                case 'F':
                co=5;
                break;
                
                case 'G':
                co=6;
                break;
                
                case 'H':
                co=7;
                break;  
                
                default:
                co=9;   
                }   
            
        
                switch (a [1]){
                case '1':
                fo=0;
                break;
                
                case '2':
                fo=1;
                break;
                
                case '3':
                fo=2;
                break;
                
                case '4':
                fo=3;
                break;
                
                case '5':
                fo=4;
                break;
                
                case '6':
                fo=5;
                break;
                
                case '7':
                fo=6;
                break;
                
                case '8':
                fo=7;
                break;  
                
                default:
                fo=9;   
                }   
        
            
            
            
                }else if (b == 1){ // coordenadas destino
            
                    switch (a [0]){
                    case 'A':
                    cd=0;
                    break;
                    
                    case 'B':
                    cd=1;
                    break;
                    
                    case 'C':
                    cd=2;
                    break;
                    
                    case 'D':
                    cd=3;
                    break;
                    
                    case 'E':
                    cd=4;
                    break;
                    
                    case 'F':
                    cd=5;
                    break;
                    
                    case 'G':
                    cd=6;
                    break;
                    
                    case 'H':
                    cd=7;
                    break;  
                    
                    default:
                    cd=9;   
                    }   
                        
                    
                    
                        
                    switch (a [1]){
                    case '1':
                    fd=0;
                    break;
                    
                    case '2':
                    fd=1;
                    break;
                    
                    case '3':
                    fd=2;
                    break;
                    
                    case '4':
                    fd=3;
                    break;
                    
                    case '5':
                    fd=4;
                    break;
                    
                    case '6':
                    fd=5;
                    break;
                    
                    case '7':
                    fd=6;
                    break;
                    
                    case '8':
                    fd=7;
                    break;  
                    
                    default:
                    fd=9;   
                    }   
            
                }       
            
                    }else{
                    fo=9; co=9; fd=9; cd=9; 
                    }//-------------------------------------------------------------------
    }
    
    void cambiarTurno(int &turno) 
	{
    // Si el turno es 1, cambia a 2; de lo contrario, cambia a 1
    turno = (turno == 1) ? 2 : 1;
	}


string TableroJuego [8][8]={{"TN","CN","AN","DN","RN","AN","CN","TN"},
                            {"PN","PN","PN","PN","PN","PN","PN","PN"},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"PB","PB","PB","--","PB","PB","PB","--"},
                            {"TB","CB","AB","DB","RB","AB","CB","TB"}
                        };
                        
string TableroLleno [8][8]={{"TN","CN","AN","DN","RN","AN","CN","TN"},
                            {"PN","PN","PN","PN","PN","PN","PN","PN"},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"PB","PB","PB","PB","PB","PB","PB","PB"},
                            {"TB","CB","AB","DB","RB","AB","CB","TB"}
                        };  
                        
                        
                        
string TableroVacio [8][8]={{"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "},
                            {"  ","--","  ","--","  ","--","  ","--"},
                            {"--","  ","--","  ","--","  ","--","  "}
                        };                      
int main (){
	
turno = 1;
A:
cout <<"\n\n\n              A          B          C          D          E          F          G          H\n\n";    
for (int i=0; i < 8; i++){
    cout <<"    "<<i+1<<"  ";
    for (int j=0; j < 8; j++){
    cout <<"       "<<TableroJuego [i][j]<<"  ";    
    }
    cout <<"\n\n";
}   
    
cout<<"--- Su turno jugador "<<turno<<" ---"<<endl;
cout <<"Ingrese las coordenadas ficha origen: ";
cin >>coord;
cout <<"\n";
Coordenadas (coord,0);
cout <<"Ingrese las coordenadas destino: ";
cin >> coord;
Coordenadas (coord,1);
cout <<"\n\n";

    if ((fo == 9 ) || (co == 9 ) || (fd == 9) || (cd == 9))
    {
        cout <<"Coordenadas incorrectas, intente de nuevo!!\n\n";
        system ("pause");
        system ("cls");
        goto A;
    }

pieza = TableroJuego [fo][co]; // Sacamos la pieza del tablero para evaluar

	if(turno == 1 && pieza[1] == 'B')
	{
		
		if (pieza [0] == 'A')
    	{
        //bool despejado=true;
    
        if ((fd < fo) && (cd > co))
        {// Diagonal superior derecha
            for (int i=1; i <= ((fo-fd)-1); i++)
            {
                if ((TableroJuego [fo-i][co+i] != "  ")  && (TableroJuego [fo-i][co+i] != "--") )
                {
                    despejado=false;
                    break;  
                }
            }
        
        piezad= TableroJuego [fd][cd];
            
        } else if((fd < fo) && (cd < co))
            {//Diagonal superior izquierda
                for (int i=1; i <= ((fo-fd)-1); i++)
                {   
                    if ((TableroJuego [fo-i][co-i] != "  ")  && (TableroJuego [fo-i][co-i] != "--") )
                    {
                        despejado=false;
                        break;  
                    }
                }
        
                piezad= TableroJuego [fd][cd];
                
            } else if((fd > fo) && (cd < co))
                {//Diagonal inferior izquierda
                    for (int i=1; i <= ((fo-fd)-1); i++)
                    {   
                        if ((TableroJuego [fo+i][co-i] != "  ")  && (TableroJuego [fo+i][co-i] != "--") )
                        {
                            despejado=false;
                            break;  
                        }
                    }
            
                    piezad= TableroJuego [fd][cd];
                    
                } else if((fd > fo) && (cd > co))
                    {//Diagonal inferior derecha
                        for (int i=1; i <= ((fo-fd)-1); i++)
                        {   
                            if ((TableroJuego [fo+i][co+i] != "  ")  && (TableroJuego [fo+i][co+i] != "--") )
                            {
                                despejado=false;
                                break;  
                            }
                        }
                
                        piezad= TableroJuego [fd][cd];
                    }
    
    
        if (despejado &&  ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") || (piezad [1] == 'N' )))
        {
            
        TableroJuego [fd][cd]=pieza;
        TableroJuego [fo][co]=TableroVacio [fo][co];    
        
        }
        
    	} else if (pieza [0] == 'T')
			{//Colocar else if aca para demas piezas
        //bool despejado=true;
        	if ((fd < fo) && (cd == co))
        	{// Movimiento hacia arriba
            	for (int i=1; i <= ((fo-fd)-1); i++)
            	{
                	if ((TableroJuego [fo-i][co] != "  ")  && (TableroJuego [fo-i][co] != "--") )
                	{
                    	despejado=false;
                    	break;  
                	}
            	}
        
        	piezad= TableroJuego [fd][cd];
            
        	}	else if ((fd > fo) && (cd == co))
        		{
            		for (int i=1; i <= ((fo-fd)-1); i++)
                	{
                    	if ((TableroJuego [fo+i][co] != "  ")  && (TableroJuego [fo+i][co] != "--") )
                    	{	
                    		despejado=false;
                    		break;  
                		}
            		}
            
            	piezad= TableroJuego [fd][cd];
            
        		}	else if ((fd == fo) && (cd < co))
        			{
            			for (int i=1; i <= ((fo-fd)-1); i++)
                		{
                    		if ((TableroJuego [fo][co-i] != "  ")  && (TableroJuego [fo][co-i] != "--") )
                    		{
                    			despejado=false;
                    			break;  
                			}
            			}
            
            		piezad= TableroJuego [fd][cd];
            
        			}	else if ((fd == fo) && (cd > co))
        				{
            				for (int i=1; i <= ((fo-fd)-1); i++)
                			{
                    			if ((TableroJuego [fo][co+i] != "  ")  && (TableroJuego [fo][co+i] != "--") )
                    			{
                    				despejado=false;
                    				break;  
                				}
            				}
            
            			piezad= TableroJuego [fd][cd];
 
        				}
        
        
        	if (despejado &&  ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") || (piezad [1] == 'N' )))
        	{
            
        		TableroJuego [fd][cd]=pieza;
        		TableroJuego [fo][co]=TableroVacio [fo][co];    

        	}
        	
	    	}  else if (pieza [0] == 'P')
				{ // VALIDACION DE PEON
		
		    
				if ((fd == (fo -2)) && (cd == co) && ((TableroJuego [fo-1][co] == "  ") || (TableroJuego [fo-1][co] == "--"))  && ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") ) && (fo == 6))
				{ // Movimiento de dos filas al inicio
		    
		 			TableroJuego [fd][cd] = TableroJuego [fo][co];  // moviendo la pieza
		 			TableroJuego [fo][co] = TableroVacio [fo][co]; 
		    
				}	else if (((fo-fd) == 1) && (cd == co) && ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--")))
					{ // movimiento de un espacio hacia adelante
		    
		 				TableroJuego [fd][cd] = TableroJuego [fo][co];  // moviendo la pieza
		 				TableroJuego [fo][co] = TableroVacio [fo][co]; 
		    
					}	
		
				}	else if (pieza[0] == 'D') 
					{
		        	//Reina
		    			if ((fd < fo) && (cd == co))
		        		{ 
		            		for (int i = 1; i <= ((fo - fd) - 1); i++)
		            		{
		                		if ((TableroJuego[fo - i][co] != "  ") && (TableroJuego[fo - i][co] != "--"))
		                		{
		                    		despejado = false;
		                    		break;
		                		}
		            		}
		
		            	piezad = TableroJuego[fd][cd];
		            	
		        		}	else if ((fd > fo) && (cd == co))
		        			{
		            			for (int i = 1; i <= ((fo - fd) - 1); i++)
		            			{
		                			if ((TableroJuego[fo + i][co] != "  ") && (TableroJuego[fo + i][co] != "--"))
		                			{
		                    			despejado = false;
		                    			break;
		                			}
		            			}
		
		            		piezad = TableroJuego[fd][cd];
		        			}	else if ((fd == fo) && (cd < co))
		        				{
		            				for (int i = 1; i <= ((fo - fd) - 1); i++)
		            				{
		                				if ((TableroJuego[fo][co - i] != "  ") && (TableroJuego[fo][co - i] != "--"))
		                				{
		                    				despejado = false;
		                    				break;
		                				}
		            				}
		
		            			piezad = TableroJuego[fd][cd];
		            			
		        				}	else if ((fd == fo) && (cd > co))
		        					{
		            					for (int i = 1; i <= ((fo - fd) - 1); i++)
		            					{
		                					if ((TableroJuego[fo][co + i] != "  ") && (TableroJuego[fo][co + i] != "--"))
		                					{
		                    					despejado = false;
		                    					break;
		                					}
		            					}
		
		            				piezad = TableroJuego[fd][cd];
		            				
		        					}	else if ((fd < fo) && (cd > co))
		        						{ 
		            						for (int i = 1; i <= ((fo - fd) - 1); i++)
		            						{
		                						if ((TableroJuego[fo - i][co + i] != "  ") && (TableroJuego[fo - i][co + i] != "--"))
		                						{
		                    						despejado = false;
		                    						break;
		                						}
		            						}
		
		            					piezad = TableroJuego[fd][cd];
		        						}	else if ((fd < fo) && (cd < co))
		        							{ 
		            							for (int i = 1; i <= ((fo - fd) - 1); i++)
		            							{
		                							if ((TableroJuego[fo - i][co - i] != "  ") && (TableroJuego[fo - i][co - i] != "--"))
		                							{
		                    							despejado = false;
		                   	 							break;
		                							}
		            							}
		
		            						piezad = TableroJuego[fd][cd];
		        							}	else if ((fd > fo) && (cd < co))
		        								{ 
		            								for (int i = 1; i <= ((fo - fd) - 1); i++)
		            								{
		                								if ((TableroJuego[fo + i][co - i] != "  ") && (TableroJuego[fo + i][co - i] != "--"))
		                								{
		                    								despejado = false;
		                    								break;
		               	 								}
		            								}
		
		            							piezad = TableroJuego[fd][cd];
		            							
		        								}	else if ((fd > fo) && (cd > co))
											        { 
											            for (int i = 1; i <= ((fo - fd) - 1); i++)
											            {
											                if ((TableroJuego[fo + i][co + i] != "  ") && (TableroJuego[fo + i][co + i] != "--"))
											                {
											                    despejado = false;
											                    break;
											                }
											            }
											
											            piezad = TableroJuego[fd][cd];
											        }
		
								        if (despejado && ((TableroJuego[fd][cd] == "  ") || (TableroJuego[fd][cd] == "--") || (piezad[1] == 'N')))
								        {
								
								            TableroJuego[fd][cd] = pieza;
								            TableroJuego[fo][co] = TableroVacio[fo][co];
								        }
						        
					}	else if (pieza[0] == 'R') 
						{
						    //Rey
						    if ((fo == fd && (co == (cd - 1) || co == (cd + 1))) || (co == cd && (fo == (fd - 1) || fo == (fd + 1))) 
						    || ((fo == (fd - 1) || fo == (fd + 1)) && (co == (cd - 1) || co == (cd + 1)))) 
						    {
						        piezad = TableroJuego[fd][cd];
						
						        if ((TableroJuego[fd][cd] == "  ") || (TableroJuego[fd][cd] == "--") || (piezad[1] == 'N'))
						        {
						            TableroJuego[fd][cd] = pieza;
						            TableroJuego[fo][co] = TableroVacio[fo][co];
						        }
						    }
						}// continuen con else if para demas piezas
		cambiarTurno(turno);
    	goto A;
    	
	} else if(turno == 2 && pieza[1] == 'N')
		{
			if (pieza [0] == 'A')
	    	{
	        //bool despejado=true;
	    
	        if ((fd < fo) && (cd > co))
	        {// Diagonal superior derecha
	            for (int i=1; i <= ((fo-fd)-1); i++)
	            {
	                if ((TableroJuego [fo-i][co+i] != "  ")  && (TableroJuego [fo-i][co+i] != "--") )
	                {
	                    despejado=false;
	                    break;  
	                }
	            }
	        
	        piezad= TableroJuego [fd][cd];
	            
	        } else if((fd < fo) && (cd < co))
	            {//Diagonal superior izquierda
	                for (int i=1; i <= ((fo-fd)-1); i++)
	                {   
	                    if ((TableroJuego [fo-i][co-i] != "  ")  && (TableroJuego [fo-i][co-i] != "--") )
	                    {
	                        despejado=false;
	                        break;  
	                    }
	                }
	        
	                piezad= TableroJuego [fd][cd];
	                
	            } else if((fd > fo) && (cd < co))
	                {//Diagonal inferior izquierda
	                    for (int i=1; i <= ((fo-fd)-1); i++)
	                    {   
	                        if ((TableroJuego [fo+i][co-i] != "  ")  && (TableroJuego [fo+i][co-i] != "--") )
	                        {
	                            despejado=false;
	                            break;  
	                        }
	                    }
	            
	                    piezad= TableroJuego [fd][cd];
	                    
	                } else if((fd > fo) && (cd > co))
	                    {//Diagonal inferior derecha
	                        for (int i=1; i <= ((fo-fd)-1); i++)
	                        {   
	                            if ((TableroJuego [fo+i][co+i] != "  ")  && (TableroJuego [fo+i][co+i] != "--") )
	                            {
	                                despejado=false;
	                                break;  
	                            }
	                        }
	                
	                        piezad= TableroJuego [fd][cd];
	                    }
	    
	    
	        if (despejado &&  ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") || (piezad [1] == 'N' )))
	        {
	            
	        TableroJuego [fd][cd]=pieza;
	        TableroJuego [fo][co]=TableroVacio [fo][co];    
	        
	        }
	        
	    	} else if (pieza [0] == 'T')
				{//Colocar else if aca para demas piezas
	        //bool despejado=true;
	        	if ((fd < fo) && (cd == co))
	        	{// Movimiento hacia arriba
	            	for (int i=1; i <= ((fo-fd)-1); i++)
	            	{
	                	if ((TableroJuego [fo-i][co] != "  ")  && (TableroJuego [fo-i][co] != "--") )
	                	{
	                    	despejado=false;
	                    	break;  
	                	}
	            	}
	        
	        	piezad= TableroJuego [fd][cd];
	            
	        	}	else if ((fd > fo) && (cd == co))
	        		{
	            		for (int i=1; i <= ((fo-fd)-1); i++)
	                	{
	                    	if ((TableroJuego [fo+i][co] != "  ")  && (TableroJuego [fo+i][co] != "--") )
	                    	{	
	                    		despejado=false;
	                    		break;  
	                		}
	            		}
	            
	            	piezad= TableroJuego [fd][cd];
	            
	        		}	else if ((fd == fo) && (cd < co))
	        			{
	            			for (int i=1; i <= ((fo-fd)-1); i++)
	                		{
	                    		if ((TableroJuego [fo][co-i] != "  ")  && (TableroJuego [fo][co-i] != "--") )
	                    		{
	                    			despejado=false;
	                    			break;  
	                			}
	            			}
	            
	            		piezad= TableroJuego [fd][cd];
	            
	        			}	else if ((fd == fo) && (cd > co))
	        				{
	            				for (int i=1; i <= ((fo-fd)-1); i++)
	                			{
	                    			if ((TableroJuego [fo][co+i] != "  ")  && (TableroJuego [fo][co+i] != "--") )
	                    			{
	                    				despejado=false;
	                    				break;  
	                				}
	            				}
	            
	            			piezad= TableroJuego [fd][cd];
	 
	        				}
	        
	        
		        	if (despejado &&  ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") || (piezad [1] == 'N' )))
		        	{
		            
		        		TableroJuego [fd][cd]=pieza;
		        		TableroJuego [fo][co]=TableroVacio [fo][co];    
		
		        	}
	    
		    	}  else if (pieza [0] == 'P')
					{ // VALIDACION DE PEON
			
			    
					if ((fd == (fo +2)) && (cd == co) && ((TableroJuego [fo+1][co] == "  ") || (TableroJuego [fo+1][co] == "--"))  && ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--") ) && (fo == 1))
					{ // Movimiento de dos filas al inicio
			    
			 			TableroJuego [fd][cd] = TableroJuego [fo][co];  // moviendo la pieza
			 			TableroJuego [fo][co] = TableroVacio [fo][co]; 
			    
					}	else if (((fd-fo) == 1) && (cd == co) && ((TableroJuego [fd][cd] == "  ") || (TableroJuego [fd][cd] == "--")))
						{ // movimiento de un espacio hacia adelante
			    
			 				TableroJuego [fd][cd] = TableroJuego [fo][co];  // moviendo la pieza
			 				TableroJuego [fo][co] = TableroVacio [fo][co]; 
			    
						}	
			
					}	else if (pieza[0] == 'D') 
						{
			        	//Reina
			    			if ((fd < fo) && (cd == co))
			        		{ 
			            		for (int i = 1; i <= ((fo - fd) - 1); i++)
			            		{
			                		if ((TableroJuego[fo - i][co] != "  ") && (TableroJuego[fo - i][co] != "--"))
			                		{
			                    		despejado = false;
			                    		break;
			                		}
			            		}
			
			            	piezad = TableroJuego[fd][cd];
			            	
			        		}	else if ((fd > fo) && (cd == co))
			        			{
			            			for (int i = 1; i <= ((fo - fd) - 1); i++)
			            			{
			                			if ((TableroJuego[fo + i][co] != "  ") && (TableroJuego[fo + i][co] != "--"))
			                			{
			                    			despejado = false;
			                    			break;
			                			}
			            			}
			
			            		piezad = TableroJuego[fd][cd];
			        			}	else if ((fd == fo) && (cd < co))
			        				{
			            				for (int i = 1; i <= ((fo - fd) - 1); i++)
			            				{
			                				if ((TableroJuego[fo][co - i] != "  ") && (TableroJuego[fo][co - i] != "--"))
			                				{
			                    				despejado = false;
			                    				break;
			                				}
			            				}
			
			            			piezad = TableroJuego[fd][cd];
			            			
			        				}	else if ((fd == fo) && (cd > co))
			        					{
			            					for (int i = 1; i <= ((fo - fd) - 1); i++)
			            					{
			                					if ((TableroJuego[fo][co + i] != "  ") && (TableroJuego[fo][co + i] != "--"))
			                					{
			                    					despejado = false;
			                    					break;
			                					}
			            					}
			
			            				piezad = TableroJuego[fd][cd];
			            				
			        					}	else if ((fd < fo) && (cd > co))
			        						{ 
			            						for (int i = 1; i <= ((fo - fd) - 1); i++)
			            						{
			                						if ((TableroJuego[fo - i][co + i] != "  ") && (TableroJuego[fo - i][co + i] != "--"))
			                						{
			                    						despejado = false;
			                    						break;
			                						}
			            						}
			
			            					piezad = TableroJuego[fd][cd];
			        						}	else if ((fd < fo) && (cd < co))
			        							{ 
			            							for (int i = 1; i <= ((fo - fd) - 1); i++)
			            							{
			                							if ((TableroJuego[fo - i][co - i] != "  ") && (TableroJuego[fo - i][co - i] != "--"))
			                							{
			                    							despejado = false;
			                   	 							break;
			                							}
			            							}
			
			            						piezad = TableroJuego[fd][cd];
			        							}	else if ((fd > fo) && (cd < co))
			        								{ 
			            								for (int i = 1; i <= ((fo - fd) - 1); i++)
			            								{
			                								if ((TableroJuego[fo + i][co - i] != "  ") && (TableroJuego[fo + i][co - i] != "--"))
			                								{
			                    								despejado = false;
			                    								break;
			               	 								}
			            								}
			
			            							piezad = TableroJuego[fd][cd];
			            							
			        								}	else if ((fd > fo) && (cd > co))
												        { 
												            for (int i = 1; i <= ((fo - fd) - 1); i++)
												            {
												                if ((TableroJuego[fo + i][co + i] != "  ") && (TableroJuego[fo + i][co + i] != "--"))
												                {
												                    despejado = false;
												                    break;
												                }
												            }
												
												            piezad = TableroJuego[fd][cd];
												        }
			
									        if (despejado && ((TableroJuego[fd][cd] == "  ") || (TableroJuego[fd][cd] == "--") || (piezad[1] == 'N')))
									        {
									
									            TableroJuego[fd][cd] = pieza;
									            TableroJuego[fo][co] = TableroVacio[fo][co];
									        }
							        
						}	else if (pieza[0] == 'R') 
							{
							    //Rey
							    if ((fo == fd && (co == (cd - 1) || co == (cd + 1))) || (co == cd && (fo == (fd - 1) || fo == (fd + 1))) 
							    || ((fo == (fd - 1) || fo == (fd + 1)) && (co == (cd - 1) || co == (cd + 1)))) 
							    {
							        piezad = TableroJuego[fd][cd];
							
							        if ((TableroJuego[fd][cd] == "  ") || (TableroJuego[fd][cd] == "--") || (piezad[1] == 'N'))
							        {
							            TableroJuego[fd][cd] = pieza;
							            TableroJuego[fo][co] = TableroVacio[fo][co];
							        }
							    }
							}// continuen con else if para demas piezas
			cambiarTurno(turno);
    		goto A;
    		
		} else
			{
				cout<<"Ha seleccionado una pieza no encontrada o del jugador contrario"<<endl;
				goto A;
			}

	
    return 0;
}
