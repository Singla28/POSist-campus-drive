#include<bits/stdc++.h> //  It includes every standard header file like iostream, stdlib,vector, algorithms and other.
using namespace std;

class record{
public:
	int recordnum;	
	int data;	
	string nid;	
	record* refnid;	
	vector<record*> cref;	
	record* gennid;	//Genesisrecord
	string time-in_date ;
	// hashValue datatype not possible due to time constraint

	string hashvalue;



	// Initialize record
	record(int num,int d,record* ref,record* gen){
	recordnum = num;
	data = d;
	nid = to_string(num);
	refnid = ref;
	gennid = gen;
	}
	
	// Inserting record
	bool addrecord(int data,record* p,int num,record* gen){
	record* r;
	if(data + p->getSumChild() < p->data){
	r = new record(num,data,p,gen);
	p->cref.push_back(r);
	return true;
	}
	
	for(auto i = p->cref.begin();i!=p->cref.end();i++){
	bool flag = addrecord(data,*i,num,gen);
	if(flag){
	return true;
	}
	}
	return false;
}
bool addrecordparticular(int data,record* p,int num,record* gen){
	record* r;
	if(data + p->getsum() < p->data){
	r = new record(num,data,p,gen);
	p->cref.push_back(r);
	return true;
	}
	return false;
}
	// task 3 Encrypting the data 
	void encrypt(record *n){

    	n->isEncrypted = true;
    	cout<<"Enter owner pword";
    	cin>>n->pword;
    for(i = 0; (i < 100 && n->pword[i] != '\0'); i++)
        n->pword[i] = n->pword[i] + 2;


	}

	// task 4 Decrypting the data
	int decrypt(record *given_record,string pass){


        for(i = 0; (i < 100 && pass[i] != '\0'); i++)
        n->pass[i] = n->pass[i] + 2;

        if(given_record->pword == pass){
            return 1;
        }
        else{
            return 0;
        }
	}

	// task 7 changing ownership

	void task4owner(record *given_record){

    string pass1,pass2;
    cout<<"Owner one enter pword";
    cin>>pass;
    if(decrypt(given_record,pass)){
        cout<<"Ownership of record will be changed,enter new owner id";
        cin>>given_record->data->owner_name;
        void encrypt(given_record);
    }
	}

	// Sum of data used in the above function
	int getsum(){
	int value = 0;
	for(auto i = cref.begin();i!=cref.end();i++){
	value =value + (*i)->data;
	}
	return value;
	}
};

// task 8 Longest chain through genesis node
int lchain(record* p){
	if(p == NULL){
	return 0;
	}
	if(p->cref.size() == 0){
	return 1;
	}
	int longest= INT_MIN;  // Taking the minimum value of data from record
	for(auto i = p->cref.begin();i!=p->cref.end();i++){
	longest = max(longest,lchain(*i));
	}
	return longest + 1;
}

// Task 10
void merge(record* n1,record* n2){
	if(lchain(n1) > lchain(n2)){
	n1->data += n2->data;
	delete n2;
	return ;
	}
	n1->data += n2->data;
	delete n2;
}

// For finding address 
record* findingrecord(int data,record* p){
	if(p->data == data){
	return p;
	}
	if(p == NULL){
	return NULL;
	}
	for(auto i = p->cref.begin(); i!= p->cref.end(); i++){
	if((*i)->data == data){
	return *i;
	}
	}
	if(p->cref.size() == 0){
	return NULL;
	}
	record* x;
	for(auto i = p->cref.begin(); i!= p->cref.end(); i++){
	x = findingrecord(*i);
	}
	return x;
}

int main(){
	int num = 0;
	int data;
	cout<<"Enter Data for genesis record : ";
	cin>>data;
	record gen(++num,data,NULL,NULL);
	int values;

	cout<<"1 : Add record to genesis record or down the line if not possible for genesis record."<<endl;
	cout<<"2 : Set of child records of a particular record."<<endl;
	cout<<"3 : Creating child record from particular record "<<endl;
	cout<<"4 : Encrypting Data."<<endl;
	cout<<"7 : Changing the Ownership of record. "<<endl;
	cout<<"8 : Find longest chain of genesis record."<<endl;
	cout<<"9 : Find longest chain of record by providing address of it."<<endl;
	cout<<"10 : Merge Two records by giving data."<<endl;
	cout<<"11 : Exit"<<endl;
	cout<<"Enter value : ";
	cin>>values;
	while(values!=11)
	{
		switch(values){
	case 1: {
	cout<<"Enter data : ";
	cin>>data;
	bool add = addrecord(data,&gen,++num,&gen);
	break;
	}
	case 2: 
	{
		
		break;
	}
	case 3:
	{
		cout<<"Adding record at particular value."<<endl;
		bool addp = addrecordparticular(data,&gen,++num,&gen);
		break;		
	}
	case 4:
	{
		encrypt(&gen);
		break;
	}
case 5:
	{
		break;
	}
case 6:
	{
		break;
	}
case 7:
	{
		cout<<" Changing Ownership"<<endl;
		task4owner(&gen);
		break;
	}
case 8:
	{	
		int l=lchain(&gen);
		cout<<"Number Of nodes from genesis node ="<<l<<endl;
		break;
	}
case 9:
	{
		
		break;
	}
case 10:
	{
		merge(&gen,&gen1);  // Merging nodes 
		break;
	}
default:
{
	cout<<" Thank You for using our Code"<<endl;
	break;
}
	} 
	}
	return 0;
}


// A vector of records is converted into tree. Then node is added at particular address an following the merge operation , longest chain operation 