#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//MENU FUNCTIONS
void tablemenu()
{
	
	printf("|****************RESTAURANT MANAGEMENT SYSTEM*****************|\n");
	printf("|**********TABLES****************************TOTAL************|\n");

}

void othermenu1()
{
	printf("|***************RESTAURANT MANAGEMENT SYSTEM******************|\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
}

void othermenu2(){
    printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|                                                             |\n");
	printf("|*************************************************************|\n");
}

void enterchoise()
{   printf("|*************************************************************|\n");
	printf("|********************Enter Your Choise************************|\n");
	printf("|*****************(Back to Main Menu '1')*********************|\n");
	printf("|***********************(Exit '0')****************************|\n");
	printf("                            ");
}

void mainmenu()
{
	printf("|***************RESTAURANT MANAGEMENT SYSTEM******************|\n");
	printf("|                                                             |\n");
	printf("|                      1.TABLES                               |\n");
	printf("|                                                             |\n");
	printf("|                      2.PRODUCT MENU                         |\n");
	printf("|                                                             |\n");
	printf("|                      3.ADD-DELETE TABLE                     |\n");
	printf("|                                                             |\n");
	printf("|                      4.RESET ALL TABLES                     |\n");
	printf("|                                                             |\n");
	printf("|                      0.QUIT                                 |\n");
	printf("|                                                             |\n");
	printf("|*************************************************************|\n");
	printf("|********************Enter Your Choise************************|\n");
	printf("                            ");
}

void cafemenu()
{
	printf("|**************RESTAURANT MANAGEMENT SYSTEM*******************|\n");
	printf("|***********PRODUCT************************PRICE**************|\n");
		
}

void tablechoosemenu(){
	system("cls");
				othermenu1();
				printf("|                     1-ORDER                                 |\n");
				printf("|                     2-RESET THE TABLE                       |\n");
				printf("|                     3-BACK TO MAIN MENU                     |\n");
				othermenu2();
		        printf("                            ");
}

//FILES
FILE *hmp;
FILE *hmt;
FILE *p;
FILE *t;

float tablecost(int x,int y){
	char tablep[15];
	float totalmoney;
	float add=0;
	float cos;
	int j,i,k;
	struct product{
	    char name[15];
	    float price;	
};
	
	struct product* products2=(struct product*)malloc(100*sizeof(struct product)); 
	for(j=1;j<=x;j++){
			
		system("cls");
		p=fopen("products.txt","r");
		printf("|***************RESTAURANT MANAGEMENT SYSTEM******************||********************************|\n");
						
		for(k=0;k<4;k++){
			fscanf(p,"%s",(products2+k)->name);
            fscanf(p,"%f",&(products2+k)->price);		
        	printf("|                                                             || %3d-%-15s    %6.2f  |\n",k+1,(products2+k)->name,(products2+k)->price);
        }
                     
        for(k=4;k<5;k++){
			fscanf(p,"%s",(products2+k)->name);
            fscanf(p,"%f",&(products2+k)->price);        
            printf("|                TYPE  PRODUCT NAME  ->%2d:                    || %3d-%-15s    %6.2f  |\n",j,k+1,(products2+k)->name,(products2+k)->price);
        }
        
        for(k=5;k<y;k++){
		fscanf(p,"%s",(products2+k)->name);
        fscanf(p,"%f",&(products2+k)->price);
   	    printf("|                                                             || %3d-%-15s    %6.2f  |\n",k+1,(products2+k)->name,(products2+k)->price);  
        }
        
        printf("|*************************************************************||********************************|\n");
	    printf("                            ");
					
        scanf("%s",tablep);
		cos=atof(tablep);
		  
		p=fopen("products.txt","r");
					
		for(i=0;i<y;i++){
					
            fscanf(p,"%s",(products2+i)->name);
            fscanf(p,"%f",&(products2+i)->price);
            
            if(strcmp(tablep,(products2+i)->name)==0)
                totalmoney=(products2+i)->price;
            if(cos==(i+1))
                totalmoney=(products2+i)->price;
        }
                       	
        fclose(p);           
		add+=totalmoney;	
	}
	
	return add;
}

float costadding(int x,int y,int z,int tnum){
	FILE *t;
	float beforeadd;
	int i;
	struct table{
		float cost;
	};	
	struct table* tables=(struct table*)malloc(15*sizeof(struct table)); 
	
	if(x==1){
	
	    system("cls");
	    float adding;
		float total;
		int n3;
		othermenu1();
		printf("|              How Many Products Do You Add?                  |\n");
		othermenu2();
		printf("                            ");
		scanf("%d",&n3);
						
		adding=tablecost(n3,y);	
			        
		t=fopen("tablecosts.txt","r");
			        
			for(i=1;i<tnum;i++){
				if(i==z){
					
		          	fscanf(t,"%f\n",&(tables+i)->cost);
		            beforeadd=(tables+i)->cost;
				  
				  }
				else{
				  
				  fscanf(t,"%f\n",&(tables+i)->cost);
				 
		    	}
	     	}
	     	
			fclose(t);
			
		    total=adding+beforeadd;
		          	
			system("cls");
			othermenu1();
			printf("|                     TOTAL COST : %6.2f                     |\n",total);
		    othermenu2();
		    enterchoise();
		    printf("                            ");
			        
		    beforeadd=total;
		        
		    t=fopen("tablecosts.txt","w");
		    for (i=1;i<tnum;i++){
                if(i==z){
						
                    (tables+i)->cost=beforeadd;
                    fprintf(t,"%f\n",(tables+i)->cost);
                    
                    }
                    else
                       fprintf(t,"%f\n",(tables+i)->cost);
                    }
		       
		         	fclose(t);
	}
		         
	else if(x==2){
		
		t=fopen("tablecosts.txt","r");
			        
		for(i=1;i<tnum;i++){
			if(i==z){
					
		        fscanf(t,"%f\n",&(tables+i)->cost);
		        (tables+i)->cost=0;
				  
		    }
			else{
				fscanf(t,"%f\n",&(tables+i)->cost);
			}
		}
		fclose(t);
			        
		t=fopen("tablecosts.txt","w");
		    for (i=1;i<tnum;i++)
                fprintf(t,"%f\n",(tables+i)->cost);
                    
		    fclose(t);
	}
	
	if(x==3){
		t=fopen("tablecosts.txt","r");
			        
		for(i=1;i<tnum;i++){
					
		    fscanf(t,"%f\n",&(tables+i)->cost);
		    (tables+i)->cost=0;
				  	
		}
		fclose(t);
			        
		t=fopen("tablecosts.txt","w");
		for (i=1;i<tnum;i++)
            fprintf(t,"%f\n",(tables+i)->cost);
                    
		fclose(t);
	
	}
}
	
struct product{
	 char name[15];
	 float price;
	 
};

struct table{
		float cost;
	};	
	
	
int main() {
	
	int tchoise;
    int howmanyt,howmanyp;
	int tableno;
	int i,j,k,ht;
	int n,n2,lastchoise;
    int parr[100];
    
    int addtable;
	int aord;
	int tnum2;
	int beforeadd2;
    int aord2;
	int arrt;
    float price,addprice;
    
    char addproduct[10];
	char product[10];
	struct table* tables=(struct table*)malloc(15*sizeof(struct table)); 
    struct product* products=(struct product*)malloc(100*sizeof(struct product));
    struct product* products2=(struct product*)malloc(100*sizeof(struct product));   
		
	
	
	

    if((hmt=fopen("howmanytables.txt","r"))==NULL){
    	
    	hmt=fopen("howmanytables.txt","w");
    	fprintf(hmt,"11");
    	fclose(hmt);
    	
	}	
	
	if((hmp=fopen("howmanyproducts.txt","r"))==NULL){
	
		hmp=fopen("howmanyproducts.txt","w");
		fprintf(hmp,"12");
		fclose(hmp);
	
	}
		
	fclose(p);
		
	if((p=fopen("products.txt","r"))==NULL){
	
		p=fopen("products.txt","w");
		
		fprintf(p,"burger 20\n");
		fprintf(p,"pizza 25\n");
		fprintf(p,"spaghetti 15\n");
		fprintf(p,"chicken 15\n");
		fprintf(p,"soup 8\n");
		fprintf(p,"beef 35\n");
		fprintf(p,"cola 4\n");
		fprintf(p,"water 2\n");
		fprintf(p,"redbull 7\n");
		fprintf(p,"soda 3\n");
		fprintf(p,"coffee 8\n");
		fprintf(p,"fanta 4\n");
		
		fclose(p);

}
		
	if((t=fopen("tablecosts.txt","r"))==NULL){
				
		if((hmt=fopen("howmanytables.txt","r"))==NULL){
				
			t=fopen("tablecosts.txt","w");
		    for (i=1;i<11;i++)
                fprintf(t,"0\n");
                    
		        fclose(t);
		}
		         
		else{
		    hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);
			
		    t=fopen("tablecosts.txt","w");
		    for (i=1;i<howmanyt;i++)
                fprintf(t,"0\n");
                    
		    fclose(t);
	    }	         
	}
	main:	
		
    system("cls");
	mainmenu();
	scanf("%d",&n);
			
	switch(n){
		//Exit
		case 0:
			
			fflush(stdin);
			printf("DEVELOPED BY YUSUF TARIK LIMAN AND YAGIZ BABUROGLU");
			break;
		//Table Menu
		case 1:
			
			system("cls");
			fflush(stdin);
		    tablemenu();
		    
		    t=fopen("tablecosts.txt","r");
			hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);  
			
		    for(i=1;i<howmanyt;i++){
				
		        fscanf(t,"%f\n",&(tables+i)->cost);
		        printf("|          TABLE-%2d                         %6.2f            |\n",i,(tables+i)->cost);
		            
         	}
			fclose(t);
			       
			printf("|*************************************************************|\n");
        	printf("|********************Enter Your Choise************************|\n");
        	printf("                            ");
			scanf("%d",&tchoise);
			
			hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);
			
			if(tchoise>howmanyt){
				
				system("cls");
	         	othermenu1();
	        	printf("|                   PLEASE ADD NEW TABLE                      |\n");
	        	othermenu2();
	        	enterchoise();
				
			}
		
			else{
			
			hmp=fopen("howmanyproducts.txt","r");
			fscanf(hmp,"%d",&howmanyp);
			
			tablechoosemenu();
				
			scanf("%d",&n2);		
					
			if(n2==1){
					
				costadding(1,howmanyp,tchoise,howmanyt);
						
				}
				
			else if(n2==2)
				{
				costadding(2,howmanyp,tchoise,howmanyt);
				system("cls");
				othermenu1();
				printf("|          The Table Has Been Successfully Reseted            |\n");
		     	othermenu2();
			    enterchoise();
				}
			
				else if(n2==3)
				    enterchoise();
				else{
				    system("cls");
		            othermenu1();
                	printf("|                      INVALID NUMBER                         |\n");
            		othermenu2();
     	        	enterchoise();
				}
            }
		break;
			//Product Menu
		case 2:
			
			
			system("cls");
			fflush(stdin);
			
			for(arrt=0;arrt<100;arrt++)
			parr[arrt]=arrt+1;
			
			cafemenu();
			hmp=fopen("howmanyproducts.txt","r");
	        fscanf(hmp,"%d",&howmanyp);
           	fclose(hmp);
			
			p=fopen("products.txt","r");
			for(k=0;k<howmanyp;k++)
				{fscanf(p,"%s",(products2+k)->name);
              	fscanf(p,"%f",&(products2+k)->price);
          	printf("|  %3d-     %-15s                 %6.2f            |\n",parr[k],(products2+k)->name,(products2+k)->price);
			}
		
			fclose(p);
			printf("|*************************************************************|\n");
			printf("| 1.Add Product                                               |\n");
			printf("| 2.Delete Product                                            |\n");
			printf("| 3.Back to Main Menu                                         |\n");
			printf("|*************************************************************|\n");
			  
//Add-Delete Product			  
	     	scanf("%d",&aord2);
            if(aord2==1){
		 	
		 		hmp=fopen("howmanyproducts.txt","r");
             	fscanf(hmp,"%d",&howmanyp);
             	fclose(hmp);
	
             	howmanyp+=1;
	
             	hmp=fopen("howmanyproducts.txt","w");
               	fprintf(hmp,"%d",howmanyp);
            	fclose(hmp);
			
		     	fflush(stdin);
			
		    	printf("Type Product Name:\n");
		    	scanf("%s",(products)->name);
			
	       		printf("Enter Cost of The Product:\n"); 
		
	     		scanf("%f",&(products)->price);
	     		p=fopen("products.txt","a");
	      		fprintf(p,"%s %f\n",(products)->name,(products)->price);
	     		fclose(p);
		 	
		    }
            else if(aord2==2){
	 
			    int ch5,v,con;
			    
		        printf("Enter The Number of The Product:\n");
			    scanf("%d",&ch5);
			    
			    p=fopen("products.txt","r");
				for(v=0;v<howmanyp;v++)
				{
			       	fscanf(p,"%s",(products2+v)->name);
                	fscanf(p,"%f",&(products2+v)->price);
		     	}
			    fclose(p);
			    
			    p=fopen("products.txt","w");
			    for(v=0;v<howmanyp;v++)
			    {
			    	if(v!=ch5-1){
						fprintf(p,"%s %f\n",(products2+v)->name,(products2+v)->price);
			    }
			    
				}
				 
				fclose(p);
			   	hmp=fopen("howmanyproducts.txt","r");
             	fscanf(hmp,"%d",&howmanyp);
            	fclose(hmp);
	
             	howmanyp-=1;
	
             	hmp=fopen("howmanyproducts.txt","w");
               	fprintf(hmp,"%d",howmanyp);
              	fclose(hmp);
            }
			system("cls");
			fflush(stdin);
			
			cafemenu();
			hmp=fopen("howmanyproducts.txt","r");
          	fscanf(hmp,"%d",&howmanyp);
          	fclose(hmp);
			
			p=fopen("products.txt","r");
			for(k=0;k<howmanyp;k++)
				{fscanf(p,"%s",(products2+k)->name);
              	fscanf(p,"%f",&(products2+k)->price);
	            printf("|  %3d-     %-15s                 %6.2f            |\n",k+1,(products2+k)->name,(products2+k)->price);
				}
			enterchoise();
			break;
		
		//Add-Delete Table
		case 3:
		
			    
			system("cls");
			othermenu1();
			printf("|                     1.ADD NEW TABLES                        |\n");
			printf("|                     2.DELETE TABLES                         |\n");
			othermenu2(); 
	    	scanf("%d",&aord);
			       
			if(aord==1){
			  
			system("cls");
			othermenu1();
			printf("|                How Many Table Do You Add?                   |\n");
		    othermenu2();
			scanf("%d",&addtable);
			    
			hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);
			beforeadd2=howmanyt;
			howmanyt+=addtable;
			
			hmt=fopen("howmanytables.txt","w");
			fprintf(hmt,"%d",howmanyt);
			fclose(hmt);
			
			t=fopen("tablecosts.txt","r");
			for(tnum2=0;tnum2<howmanyt;tnum2++)
			{
				fscanf(t,"%f\n",&(tables+tnum2)->cost);
			}
			fclose(t);
			t=fopen("tablecosts.txt","w");
			for(tnum2=0;tnum2<howmanyt;tnum2++){
			
		     	if(tnum2>=beforeadd2){
			    	(tables+tnum2)->cost=0;
			    	fprintf(t,"%f\n",(tables+tnum2)->cost);
				
		    	}
			
				else
			    	fprintf(t,"%f\n",(tables+tnum2)->cost);
			
	    	}
			fclose(t);
		
			system("cls");
			othermenu1();
			printf("|                New Tables Has Been Added                    |\n");
			othermenu2();
			
		    enterchoise();
		}
		else if(aord==2){
		      	
			system("cls");
			int deltable;
		    othermenu1();
			printf("|                How Many Table Do You Delete?                |\n");
			othermenu2();
			scanf("%d",&deltable);
					
			hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);
			
			howmanyt-=deltable;
			
			hmt=fopen("howmanytables.txt","w");
			fprintf(hmt,"%d",howmanyt);
			fclose(hmt);
			system("cls");
			othermenu1();
			printf("|                  Tables  Has Been Deleted                   |\n");
			othermenu2();
			enterchoise();
		}
			  
		else{
			system("cls");
	    	othermenu1();
		    printf("|                      INVALID NUMBER                         |\n");
	    	othermenu2();
	    	enterchoise();
		}
			
			break;
		//Reset All Tables	
		    case 4:
		    	
		    hmt=fopen("howmanytables.txt","r");
			fscanf(hmt,"%d",&howmanyt);
			fclose(hmt);
		    		
		    system("cls");
		    othermenu1();
		    printf("|               All Tables Has Been Reseted                   |\n");
		    othermenu2();
		    costadding(3,howmanyp,tableno,howmanyt);
		    enterchoise();	
		   	break;
				
	}
	//go to back
	if(n>4){
		system("cls");
		othermenu1();
		printf("|                      INVALID NUMBER                         |\n");
		othermenu2();
		enterchoise();
	}
	if(n!=0){
	
	scanf("%d",&lastchoise);
	switch(lastchoise){
		
		case 1:
			goto main;
			
		case 0:
			break;			
	}
}
	return 0;
}
