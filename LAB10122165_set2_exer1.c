/* Χρήστος Ζήσκας 2014030191*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 128


typedef struct									/*Prototypo 1hs Domis*/
{											/*periexei toys kodikoys kai tis posothtes*/
	int code_ofrawmaterial;			/*apo tis opoies apoteleite kapoio endiameso iliko*/			
	int quantity_of_rawmaterial;  /*xrisimopoieite diktis pou dixnei pros auti ti domi*/
}intermediate;

typedef struct						/*Prototipo 2hs Domis*/
{								/*periexei os meloi tous kodikous ,ta onomata,ton arithmo apothematon*/
	int code_of_material;	/*ton arithmo ton apetoumenon monadon kathe ilikou pou prosdiorizete apo ton arithmo ton paragelion*/
	char *name_of_material;		/*enan arithmo pou deixnei apo posa ilika apoteleite to iliko(0 einai prwti ili)*/
	int number_of_pieces;
	int needed;						/*kai episis enan dikti pou dixnei sthn 1h domi kai dieukolinei thn anagnorisi ton endiameson ilikon*/
	int number_of_Uses;	
	intermediate* intermediate_ptr;
}main_product;

/*h dilosi ton sinartision pou xrisimopoiei to programma*/
/*h prwti sinartisi anaferei tis prwtes iles apo tis opoies apoteleite kapio endiameso iliko pou orizei o xristis*/
/*h deuteri sinartisi prosdiorizei tis apaitoumenes monades simfona me tis paraggelies(kalontas ton euato tis-anadromiki) kai tis apothikeuei sto needed*/

void composition_function(main_product *main_product_pointer,char productname_array[],int number_of_products);
int recursive_function(main_product *main_product_pointer,int order_code,int order_quantity,int number_of_products,int auxiliary_variable);

int main()
{
	int i,j,temp,d;										/*Dilosi Metavliton*/
	int materials_number;
	int flag,users_second_answer;
	char users_first_answer;
	int orders_number,code_of_order,quantity_of_order;
	char buffer[MAX_NAME],users_third_answer[MAX_NAME];
	FILE *fp,*fs;										/*Dilosi deikton pros arxeia*/
	
	
	
	main_product* main_product_ptr=NULL;	/*Dilosi deikti pou dixnei sto prototipo domis main_product*/ 			
	intermediate* intermediate_ptr=NULL;	/*Dilosi deikti pou dixnei sto prototipo domis intermediate*/
	flag=0;							

	
	printf("Welcome to Material Management Program\n\n");
	
	do
	{
		printf("Do you want to open the file(y/n)? : ");		/*Elegxos gia thn apantisi tou xristi*/
		scanf(" %s", &users_first_answer);						/*Apodekti mono yes or no*/
		
	}while(users_first_answer!='y'&&users_first_answer!='n' &&users_first_answer!='N' &&users_first_answer!='Y');
	printf("\n");
	



	
	if(users_first_answer=='y'||users_first_answer=='Y')
	{
		
		fp=fopen("datain.txt", "r");			/*gia thetiki apantisi anigei to arxeio mesa apo ton deikti*/
		if(fp==NULL)							/*Elegxos an dn exei pragmatopoieithei sosta to anoigma tou arxeiou*/
		{
			printf("There was an error opening the file");
			return 0;
		}
		fscanf(fp,"%d\n", &materials_number);		/*diavasma tou arithmou twn ilikon mesa apo to arxeio datain*/
		main_product_ptr=(main_product *)malloc(sizeof(main_product)*materials_number);		 /*desmeute h apaitoumeni mnimi simfona me ton arithmo ton ilikon kai apothikeuete sto deikti pou dixxnei sto sto prototipo main_product*/	
		
		for(i=0;i<materials_number;i++)
		{
			fscanf(fp,"%d %s %d %d", &main_product_ptr[i].code_of_material,buffer, &main_product_ptr[i].number_of_pieces, &main_product_ptr[i].number_of_Uses); /*diavazontai to onoma, o kodikos, to apothema*/
			main_product_ptr[i].name_of_material=(char*)malloc((strlen(buffer)+1)*sizeof(char));				/*o arithmos apo ta ilika pou apoteleite kathe iliko*/
			strcpy(main_product_ptr[i].name_of_material,buffer);												/*desmeuetai h aparaititi mnimi gia to to melos tou struct me ta onomata*/
			main_product_ptr[i].needed=0;																	/*antigrafete to periexomeno tou pinaka buff p periexei to onoma, sto deikti pou dixnei sto melos me ta onomata prototypou main_product*/
			
			if(main_product_ptr[i].number_of_Uses<=0)		/*an isxiei auti h sinthiki simenei oti to proion einai prwti ili*/
			{
				main_product_ptr[i].intermediate_ptr=NULL;	/*o deiktis prototypou intermediate pernei timi NULL*/ 
			}
			if(main_product_ptr[i].number_of_Uses>0)		/*an isxei h sinthiki tote to proion einai sintheto*/
			{
				main_product_ptr[i].intermediate_ptr=(intermediate*)malloc(sizeof(intermediate)*main_product_ptr[i].number_of_Uses);	/*desmeuetai h analogi mnimi gia ton ekastote arithmo apo ta opoia apoteleite to iliko*/
				for(j=0;j<main_product_ptr[i].number_of_Uses;j++)
				{
					fscanf(fp," %d %d\n", &main_product_ptr[i].intermediate_ptr[j].code_ofrawmaterial,&main_product_ptr[i].intermediate_ptr[j].quantity_of_rawmaterial); /*diavazete h posothta kai o kodikos ton prwton ilon apo ta opoia apoteleite to endiameso proion*/
				}
			}
		}
		
		fscanf(fp,"%d\n",&orders_number);		/*diavazete o arithmos ton paragelion*/		
		for(i=0;i<orders_number;i++)
		{
			fscanf(fp,"%d %d\n",&code_of_order, &quantity_of_order); /*diavazete o kodikos tou proiontos kai h posothta tou gia paragelia*/
			for(j=0;j<materials_number;j++)
			{
				if(code_of_order==main_product_ptr[j].code_of_material) /*elegxei pio iliko antistixei sthn paraggelia*/
				{
					main_product_ptr[j].needed=quantity_of_order;		/*auxanete to needed gia ton kodiko tou ilikou pou antistoixei sthn paragelia*/
					temp=1;														/*voithitiki metavliti*/
		  	        recursive_function(main_product_ptr, code_of_order, quantity_of_order, materials_number, temp);
				}
			}
		}
		fclose(fp);
		
		
		
		
		
		while(flag==0)
		{
			printf("Press '1' to display the materials and their quantity in stock.\n");   /*Menou Epilogon tou programmatos*/
			printf("Press '2' to show a composite material you specify.\n");			/*1 gia na emfanisei ola ta ilika	 kai ton arithmo apothematos*/
			printf("Press '3' to  exit.\n");											/*2 gia na emfanisei ta ilika apo ena sintheto iliko kathos kai ton arithmo tou apothematos auton*/
			printf("Press '4' to create the output file.\n");						/*3 exodos apo to arxeio*/
			printf("Tell us your final answer: ");									/*4 dimiourgia arxeio exodou*/
			do
			{
				scanf(" %d", &users_second_answer);										/*h apantisi tou xristi prepei na einai arithmos apo to 1 mexri to 4*/
				printf("\n");																/*alliws xanadinei apantisi*/
				if(users_second_answer!=4 &&users_second_answer!=1 &&users_second_answer!=2 &&users_second_answer!=3)
				{
					printf("The answer you gave does not represent anyone of menu's options'.\nPlease choose an appropriate option!\n\n");
				}				
			}while(users_second_answer>4 &&users_second_answer<1);
			
			printf("\n");
			
			if(users_second_answer==1)
			{
					for(i=0;i<materials_number;++i)										/*gia apantisi 1 emfaniszei ola ta ilika kai ta apothemata*/
					{
						printf("Products identity is %s and its quantity in the storage is %d", main_product_ptr[i].name_of_material, main_product_ptr[i].number_of_pieces);
						printf("\n");
					}
					printf("\n");
			}
			else if(users_second_answer==2)
			{
				printf("Whose material do you want to see his components? ");	/*o xristis dinei to onoma tou ilikou*/
				scanf(" %s",users_third_answer);
				composition_function(main_product_ptr, users_third_answer, materials_number);
				
				printf("\n");
				

			}
			else if(users_second_answer==3)
			{
				flag=1;
				printf("You have just selected the output mode.\nEnjoy your work.\nHave a nice day!");  /*gia apantisi 3 exodos apo to programma*/
			}
			else if(users_second_answer==4)
			{
				fs=fopen("dataout.txt", "w");			/*gia apantisi 4 dimiaourgei ena neo arxeio dataout to opoio*/
				for(i=0;i<materials_number;i++)			/*periexei tous kodikous,ta onomata, ta apothemata ton ilikon kai thn anagkaia posothta tou kathenos gia thn ektelesi ths paragelias*/
				{
					fprintf(fs,"%d", main_product_ptr[i].code_of_material);
					fprintf(fs,"/");						
					fprintf(fs,"%s", main_product_ptr[i].name_of_material);
					fprintf(fs," - ");
					fprintf(fs,"%d units in stock", main_product_ptr[i].number_of_pieces);
					fprintf(fs, " - ");
					fprintf(fs, "%d units needed\n", main_product_ptr[i].needed);
				}
				fclose(fs);		/*klisimo tou arxeiou exodou*/
				printf("Your output file has been created!\n\n"); /*oloklirosi dhmiourgias arxeio*/

			}
	
	
		}

	}
	
	if(users_first_answer=='N'||users_first_answer=='n')  /*gia arnitiki apantisi anigmatos arxeio to programma klinei*/
		printf("Thank you for your time!!");
		
	 fclose(fp);						/*klisimo tou arxeio eisodou*/

	
}



int recursive_function(main_product *main_product_pointer,int order_code,int order_quantity,int number_of_products, int auxiliary_variable)
{
	int i;
	int j;													/*anadromiki sinartisi*/
	int temp;
	for(i=0;i<number_of_products;i++)
	{
		if(main_product_pointer[i].code_of_material==order_code)  /*an o kodikos ths paragelias einai idios me kapoion apo tous kodikous tou dixti pou dixnei sto melos ths domis struct*/
		{																/*kai to iliko pou antistoixei ston epilegmeno kodiko dn einai prwti ili*/
			if(main_product_pointer[i].number_of_Uses!=0)
			{				
				for(j=0;j<main_product_pointer[i].number_of_Uses;j++)
				{
					main_product_pointer[main_product_pointer[i].intermediate_ptr[j].code_ofrawmaterial-1].needed+=main_product_pointer[i].intermediate_ptr[j].quantity_of_rawmaterial*order_quantity*auxiliary_variable;  /* o apaitoumenos arithmos paragelion gia kathe kodiko auxanete analoga me thn posothta pou xriazete gia na dimiourgithei to endiameso proion*/
				
				}
				for(j=0;j<main_product_pointer[main_product_pointer[i].intermediate_ptr[j].code_ofrawmaterial-1].number_of_Uses;j++)
				{
					auxiliary_variable=main_product_pointer[i].needed;			/*voithitiki metavliti pou krataei ton arithmo ton ilikon pou exoun metrithi*/
			    	recursive_function(main_product_pointer,main_product_pointer[i].intermediate_ptr[j].code_ofrawmaterial,main_product_pointer[i].intermediate_ptr[j].quantity_of_rawmaterial,number_of_products,auxiliary_variable);
				}
				/*xanakaleite h sinartisi*/

			}

		}
	}
}




void composition_function(main_product *main_product_pointer, char productname_array[], int number_of_products)
{																	  /*h sinartisi pou dixnei ta ilika pou apoteleite ena sintheto iliko kathos kai thn posothta tou apothematos tou*/
	int i,j;
	int code,check_strings;
	
	printf("The composite material consists of the followings accompanied by their quantity in stock:\n");
	
	for(i=0;i<number_of_products;i++)		/*elegxos an ta strings einai idia*/
	{
		check_strings=strcmp(main_product_pointer[i].name_of_material,productname_array); /*elegxos an h apantisi tou xristi antistixei se kapoio onoma proiontos.An vrei kapio tote h metavliti pernei timi 0*/
		if(check_strings==0)
		{
			for(j=0;j<main_product_pointer[i].number_of_Uses;j++) /*afou hparxei to idio onoma sta ilika kratame tous kodikous apo ta opoia apoteleite to iliko*/
			{	
					code=main_product_pointer[i].intermediate_ptr[j].code_ofrawmaterial; /*kai ektipwnei to onoma ton kodiko(o diktis meiwnete kata eina giati o pinakas xekianei apo to 0) kai thn posothta*/
					printf("%s saved on stock: %d\n",main_product_pointer[code-1].name_of_material, main_product_pointer[code-1].number_of_pieces);
			}
		}
	}
	printf("\n\n");	
}
	
	

