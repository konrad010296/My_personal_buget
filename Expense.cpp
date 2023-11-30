#include "Expense.h"

void Expense::setExpenseId(int id){
expenseId = id;
}
void Expense::setUserId(int idUser){
userId = idUser;
}
void Expense::setDate(string datee){
date = datee;
}
void Expense::setItemName(string itemName){
item = itemName;
}
void Expense::setAmount(float itemAmoutn){
amount = itemAmoutn;
}

int Expense::getExpenseId(){
return expenseId;
}
int Expense::getUserId(){
return userId;
}
string Expense::getDate(){
return date;
}
string Expense::getItemName(){
return item;
}
float Expense::getAmount(){
return amount;
}
