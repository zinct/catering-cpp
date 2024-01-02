//
//  catering.c
//  catering
//
//  Created by Indra Mahesa on 31/12/23.
//

#include <stdio.h>
#include "catering.h"

void createCateringList(CateringList &list) {
    first(list) = NULL;
}

void createFoodMenuList(FoodMenuList &list) {
    first(list) = NULL;
}

CateringAddress createCateringElement(CateringInfoType catering) {
    
}
FoodMenuAddress createFoodMenuElement(FoodMenuInfoType catering);
RelationAddress createRelationElement();

void insertCatering(CateringList &list, CateringAddress catering); // 1) Insert data parent dari depan/belakang
void insertFoodMenu(FoodMenuList &list, FoodMenuList foodMenu); // 6) Menambahkan data child

void connectCateringToFoodMenu(CateringList &list, CateringAddress catering, FoodMenuAddress foodMenu); // 7) Menghubungkan data parent ke data child

void deleteCatering(CateringList &list, CateringAddress catering); // 3) Menghapus data parent beserta relasiny
void deleteFoodMenuInCatering(CateringList &list, string foodMenuId); // 10) Menghapus data child pada parent tertentu beserta relasinya

CateringAddress findCatering(CateringList list, string id); // 4) Mencari data parent
FoodMenuAddress findFoodMenu(FoodMenuList list, string id); // 5) Mencari data child
FoodMenuAddress findFoodMenuInCatering(CateringList list, string foodMenuId); // 9) Mencari data child pada parent tertentu

int getTotalFoodMenuInCatering(CateringAddress catering); // 11) Menghitung jumlah data child dari parent tertentu

void showCateringList(CateringList list); // 2) Show all data parent
void showCateringListWithFoodMenu(CateringList list); // 8) Menampilkan seluruh data parent beserta childnya

int showHightesOrdered(FoodMenuList list); // Soal studi kasus
