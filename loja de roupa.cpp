//marcelo d almeida paz RA 0050071193

#include <stdio.h> //biblioteca do printf
#include <conio.h> //biblioteca para o getch ().
#include <iostream> //biblioteca para cin e cou, entrada e saida.
#include <fstream> //biblioteca para importar arquivos de texto.
#include <stdlib.h> //biblioteca do system.
#include <string>
#include <time.h>
#include <locale> //acentuar letras

using namespace std;
ifstream arq("lojaderoupa.txt");//abre arquivo
   char op,data[9],h[9],resp_parc,resp_desc;
   void altera_preco(), le(),grava_fat(), vendas(), mostra_fat(),mostra_preco(),alunos(),data_hoje(),hora(),parcela();
   float c,fat=0,fat_total,vc,vcs,vs,qc,qcs,qs,vppc,vppcs,vps,vt,vd,vpcd,vf,comp_parc,p_desconto,subt,val_parc,quant_parc,juros_ano,juros_total ;
   string dia,mes,ano,horas,minuto,totais;

main(){
system ("Color 1f");
  setlocale (LC_ALL,"portuguese");
  data_hoje();
  hora();
	  // 27 = código da tecla ESC
      while (op != 27)
      {
            system("cls");
            cout<<dia+"/"+mes+"/"+ano+" - "+horas+":"+minuto+"\n\n\n\n\n\n";
            cout <<"\t 1 - Altera Preço\n\n";
            cout <<"\t 2 - Mostra Preço\n\n";
            cout <<"\t 3 - Vendas\n\n";
			cout <<"\t 4 - Mostra Faturamento\n\n";
			cout <<"\t 5 - Alunos\n\n\n\n\n\n\n";
            cout <<" ESC - Sair";
            op = getch();
            switch (op)
            {
               case '1' :
                    altera_preco();
                    break;
               case '2' :
                    mostra_preco();
                    break;
               case '3' :
                    vendas();
                    break;
                case '4' :
                    mostra_fat();
                    break;
                case '5' :
					 alunos();
					 break;
               case 27 :
                    break;
               default :
                    continue;
             }
       }
}

void vendas(){

	char resp;
	float total;
	le(); //le valores dos produtos
	while(resp!='n'){
	system("cls");
	cout<<"\t\t\tloja de roupa\n\n";

    cout<<"\tdigite quantidade de calças   : ";
    cin>>qc;
    vppc=qc*vc;
    cout<<"\tvalor a pagar pelas calças    : R$ "<<vppc<<"\n\n";

	cout<<"\tdigite quantidade de camisas  : ";
    cin>>qcs;
    vppcs=qcs*vcs;
    cout<<"\to valor a pag pel camis é de  : R$ "<<vppcs<<"\n\n";

    cout<<"\tdigite quantidade de sapatos   : ";
    cin>>qs;
    vps=qcs*vs;
    cout<<"\tvalor a pagar pelas sapatos    : R$ "<<vps<<"\n\n";

	vt=vppc+vppcs+vps;

    cout<<"\tvalor total da compra é de    : R$ "<<vt<<"\n";
    
    parcela();
    fat=0;
	fat=vf;
	fat_total=fat+fat_total;
	
	grava_fat();
		         cout<<"\n\n\n\t Outro cliente (S/N) ";
               cin>>resp;
               resp=tolower(resp);
               while((resp!='s')and(resp!='n'))
               resp=getch();
	}

}

void parcela(){
	
	system("pause>>null");
	system("cls");
	cout<<"\n\n\tdeseja parcelar a compra ?\n\n(S/N):";
	cin >> resp_parc;
		if(resp_parc=='s'){
			system("cls");
			quant_parc=0;
			val_parc=0;
			cout<<"\t\t\t\t*** Parcelamento ***\n\n\n\n";
			cout<<"\t\tObs:Compras com mais de 3 parcelas terão \n\t\tjuros embutidos no valos final de 3% por parcela\n\n\n\nQuantidade de Parcelas: ";			
			cin>>quant_parc;
			if(quant_parc>3){
				//com mais de 3 parcelas, com juros de 3%
				subt=vt*3/100;
				val_parc=(quant_parc*subt+vt)/quant_parc;
				vf=quant_parc*val_parc;
				system("cls");
				cout<<"\n\n\n\tTotal da Compra: ($"<<vf<<" )\n\n\tCom ( "<<quant_parc<< " ) Parcelas De: ($"<<val_parc<<" )";			
			}
			else{
			//menos de 3 parcelas
			system("cls");
			val_parc=vt/quant_parc;
			vf=val_parc*quant_parc;			
			cout<<"\n\n\n\tTotal da Compra: ($"<<vf<<" )\n\n\tCom ( "<<quant_parc<< " ) Parcelas De: ($"<<val_parc<<" )";
		        }
		}
		else{
			//não parcelado
			cout<<"\n\n\tDesconto cliente ?\n\n(S/N):";
			cin>>resp_desc;
			//pergunta???, desconto se nao for parcelar
			if(resp_desc=='s'){
				//desconto sim
				cout<<"digite o % de desconto: ";
				cin>>p_desconto;
				subt=vt*p_desconto/100;
				vf=vt-subt;
				cout<<"\n\n\n\tTotal da Compra: ($"<<vf<<" )\n\n\tCom ($ "<<subt<<" ) De Desconto";	
			}
			else{
				//desconto não
				vf=vt;
				cout<<"\n\n\n\tTotal da Compra: ($"<<vf<<")";
			}
		}
}

void le()
{     system("cls");
      ifstream arq("lojaderoupa.txt");
      arq >> vc;
      arq >> vcs;
      arq >> vs;
      arq.close();
 }

 void mostra_preco()
{     system("cls");
      ifstream arq("lojaderoupa.txt");
      arq >> vc;
      cout << "camisa:" << vc << "\n";
      arq >> vcs;
      cout << "calças:" << vcs << "\n";
      arq >> vs;
      cout << "sapato:" << vs << "\n";
      system("pause>>null");
      arq.close();
 }

 void altera_preco()
 {system("cls");
      ofstream arq("lojaderoupa.txt");
      cout << "Valor camisa:";
      cin >> vc;
      arq << vc <<"\n";
      cout << "Valor calças:";
      cin >> vcs;
      arq << vcs << "\n";
      cout << "Valor sapato:";
      cin >> vs;
      arq << vs << "\n";
      arq.close();}

void grava_fat(){
    string gravacao;
    gravacao=dia+"/"+mes+"/"+ano+"_-_"+horas+":"+minuto;
    ofstream arq("fat.txt",ofstream::app);
    arq <<"\n"<<gravacao<<")_totalizador:($"<<fat_total<<")_venda:($"<<fat<<")_parcelas_("<<quant_parc<<")_de_($"<<val_parc<<")";
    arq.close();
}

void mostra_fat(){
	system("cls");
	string valor, soma;
	ifstream arq("fat.txt");
	while (!arq.eof()){
		arq >> valor;
		cout << valor<<"\n";
	}
	system("pause>>null");}

void data_hoje(){
	string x;
	_strdate(data);
	x=data;
	mes=x.substr(0,2);
	dia=x.substr(3,2);
	ano=x.substr(6,2);
	}

void hora(){
	string x;
	_strtime(h);
	x=h;
	horas=x.substr(0,2);
	minuto=x.substr(3,2);
	}
	
	void alunos(){
	system("cls");	
	cout<<"\n\n\nMarcelo de Almeida Paz RA:0050071193\n";
	cout<<"\n\Tiago das Neves Marcelino RA:0030006230\n\n";
	cout<<"Davi Soares dos Santos RA:0050062617\n\n";
	cout<<"Lucia braz s. Barreto RA:0050078942\n\n";
	cout<<"Lucas Alcantara Rodrigues RA:0050057843";
	system("pause>>null");
}

