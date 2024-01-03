//
//  catering.h
//  catering
//
//  Created by Indra Mahesa on 31/12/23.
//

#ifndef catering_h
#define catering_h

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define firstChild(P) P->firstChild
#define foodMenu(P) P->foodMenu

#include <iostream>
using namespace std;

// Define Food Menu Structure Data
struct FoodMenu {
    int id;
    string name;
    int totalOrdered;
};

typedef FoodMenu FoodMenuInfoType;
typedef struct FoodMenuElement *FoodMenuAddress;

struct FoodMenuElement {
    FoodMenuInfoType info;
    FoodMenuAddress next;
    FoodMenuAddress prev;
};

// Define Relation Structure Data
typedef struct RelationElement *RelationAddress;

struct RelationElement {
    RelationAddress next;
    FoodMenuAddress foodMenu;
};

// Define Catering Structure Data
struct Catering {
    int id;
    string name;
    int price;
};

typedef Catering CateringInfoType;
typedef struct CateringElement *CateringAddress;

struct CateringElement {
    CateringInfoType info;
    CateringAddress next;
    RelationAddress firstChild;
};

// Define datastore
struct CateringList {
    CateringAddress first;
};

struct FoodMenuList {
    FoodMenuAddress first;
};
	
// Define Function here
void createCateringList(CateringList &list);
void createFoodMenuList(FoodMenuList &list);

CateringAddress createCateringElement(CateringInfoType cateringData);
FoodMenuAddress createFoodMenuElement(FoodMenuInfoType foodMenuData);
RelationAddress createRelationElement();

void insertCatering(CateringList &list, CateringAddress catering); // 1) Insert data parent dari depan/belakang
void insertFoodMenu(FoodMenuList &list, FoodMenuAddress foodMenu); // 6) Menambahkan data child

void connectCateringToFoodMenu(CateringAddress &catering, FoodMenuAddress &foodMenu); // 7) Menghubungkan data parent ke data child

void deleteCatering(CateringList &list, CateringAddress &catering); // 3) Menghapus data parent beserta relasiny
void deleteFoodMenu(FoodMenuList &list, FoodMenuAddress &foodMenu);
void deleteFoodMenuInCatering(CateringAddress &catering, FoodMenuAddress &foodMenu); // 10) Menghapus data child pada parent tertentu beserta relasinya

CateringAddress findCatering(CateringList list, int id); // 4) Mencari data parent
FoodMenuAddress findFoodMenu(FoodMenuList list, int id); // 5) Mencari data child
FoodMenuAddress findFoodMenuInCatering(CateringAddress catering, int foodMenuId); // 9) Mencari data child pada parent tertentu

int getTotalFoodMenuInCatering(CateringAddress catering); // 11) Menghitung jumlah data child dari parent tertentu
int getMaxCateringID(CateringList list);
int getMaxFoodMenuID(FoodMenuList list);

void showCateringList(CateringList list); // 2) Show all data parent
void showFoodMenuList(FoodMenuList list);
void showFoodMenuInRelation(RelationAddress relation);

void showCateringListWithFoodMenu(CateringList list); // 8) Menampilkan seluruh data parent beserta childnya

FoodMenuAddress showHightesOrdered(FoodMenuList list); // Soal studi kasus

#endif /* catering_h */
