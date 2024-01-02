//
//  catering.cpp
//  catering
//
//  Created by Indra Mahesa on 31/12/23.
//

#include <iostream>
#include "catering.h"

void createCateringList(CateringList &list) {
    first(list) = NULL;
}

void createFoodMenuList(FoodMenuList &list) {
    first(list) = NULL;
}

CateringAddress createCateringElement(CateringInfoType cateringData) {
    CateringAddress catering = new CateringElement;
    info(catering) = cateringData;
    next(catering) = NULL;
    firstChild(catering) = NULL;
    return catering;
}

FoodMenuAddress createFoodMenuElement(FoodMenuInfoType foodMenuData) {
    FoodMenuAddress foodMenu = new FoodMenuElement;
    info(foodMenu) = foodMenuData;
    next(foodMenu) = NULL;
    prev(foodMenu) = NULL;
    return foodMenu;
}

RelationAddress createRelationElement() {
    RelationAddress relation = new RelationElement;
    next(relation) = NULL;
    foodMenu(relation) = NULL;
    return relation;
}

void insertCatering(CateringList &list, CateringAddress catering) { // 1) Insert data parent dari depan/belakang
    if (first(list) == NULL){
       first(list) = catering;
    } else {
        CateringAddress iteration = first(list);
        while(next(iteration) != NULL) {
            iteration = next(iteration);
        }
        
        next(iteration) = catering;
    }
}

void insertFoodMenu(FoodMenuList &list, FoodMenuAddress foodMenu) { // 6) Menambahkan data child
    if (first(list) == NULL){
       first(list) = foodMenu;
    } else {
        FoodMenuAddress iteration = first(list);
        while(next(iteration) != NULL) {
            iteration = next(iteration);
        }
        
        prev(foodMenu) = iteration;
        next(iteration) = foodMenu;
    }
}
    
void connectCateringToFoodMenu(CateringAddress &catering, FoodMenuAddress &foodMenu) { // 7) Menghubungkan data parent ke data child
    RelationAddress relation = createRelationElement();
    foodMenu(relation) = foodMenu;
    
    if(firstChild(catering) == NULL) {
        firstChild(catering) = relation;
    } else {
        RelationAddress iteration = firstChild(catering);
        while(next(iteration) != NULL) {
            iteration = next(iteration);
        }
        next(iteration) = relation;
    }
}
    
void deleteCatering(CateringList &list, CateringAddress &catering) { // 3) Menghapus data parent beserta relasinya
    if(first(list) == catering) {
        first(list) = NULL;
    } else {
        CateringAddress iteration = first(list);
        while(next(iteration) != catering) {
            iteration = next(iteration);
        }
        
        next(iteration) = next(next(iteration));
        firstChild(iteration) = NULL;
    }
}

void deleteFoodMenu(FoodMenuList &list, FoodMenuAddress &foodMenu) {
    
}

void deleteFoodMenuInCatering(CateringAddress &catering, FoodMenuAddress &foodMenu) { // 10) Menghapus data child pada parent tertentu beserta relasinya
    if(foodMenu(firstChild(catering)) == foodMenu) {
        firstChild(catering) = NULL;
    } else {
        RelationAddress iteration = firstChild(catering);
        while(foodMenu(next(iteration)) != foodMenu) {
            iteration = next(iteration);
        }
        
        next(iteration) = next(next(iteration));
    }
}
    
CateringAddress findCatering(CateringList list, int id) { // 4) Mencari data parent
    if(info(first(list)).id == id) {
        return first(list);
    }
    
    CateringAddress catering = NULL;
    CateringAddress iteration = first(list);
    
    while(iteration != NULL && catering == NULL) {
        if(info(iteration).id == id) {
            catering = iteration;
        }
        
        iteration = next(iteration);
    }
    
    return catering;
}

FoodMenuAddress findFoodMenu(FoodMenuList list, int id) { // 5) Mencari data child
    if(info(first(list)).id == id) {
        return first(list);
    }
    
    FoodMenuAddress foodMenu = NULL;
    FoodMenuAddress iteration = first(list);
    
    while(iteration != NULL && foodMenu == NULL) {
        if(info(iteration).id == id) {
            foodMenu = iteration;
        }
        
        iteration = next(iteration);
    }
    
    return foodMenu;
}

FoodMenuAddress findFoodMenuInCatering(CateringList list, string foodMenuId); // 9) Mencari data child pada parent tertentu

int getTotalFoodMenuInCatering(CateringAddress catering); // 11) Menghitung jumlah data child dari parent tertentu
int getMaxCateringID(CateringList list) {
    if(first(list) == NULL) {
        return 0;
    }
    
    int max = 0;
    CateringAddress iteration = first(list);
    while(iteration != NULL) {
        if(info(iteration).id > max) {
            max = info(iteration).id;
        }
        iteration = next(iteration);
    }
    
    return max;
}

int getMaxFoodMenuID(FoodMenuList list) {
    if(first(list) == NULL) {
        return 0;
    }
    
    int max = 0;
    FoodMenuAddress iteration = first(list);
    while(iteration != NULL) {
        if(info(iteration).id > max) {
            max = info(iteration).id;
        }
        iteration = next(iteration);
    }
    
    return max;
}

void showCateringList(CateringList list) { // 2) Show all data parent
    CateringAddress iteration = first(list);
    
    if(iteration == NULL) {
        cout << "Data catering kosong!" << endl;
    } else {
        while(iteration != NULL) {
            cout << "ID : " << info(iteration).id << endl;
            cout << "Nama : " << info(iteration).name << endl;
            cout << "Harga : " << info(iteration).price << endl;
            
            iteration = next(iteration);
        }
    }
}

void showFoodMenuList(FoodMenuList list) {
    FoodMenuAddress iteration = first(list);
    
    if(iteration == NULL) {
        cout << "Data menu kosong!" << endl;
    } else {
        while(iteration != NULL) {
            cout << "ID : " << info(iteration).id << endl;
            cout << "Nama : " << info(iteration).name << endl;
            cout << "Total Terjual : " << info(iteration).totalOrdered << endl;
            
            iteration = next(iteration);
        }
    }
}

void showCateringListWithFoodMenu(CateringList list) { // 8) Menampilkan seluruh data parent beserta childnya
    CateringAddress cateringIteration = first(list);
    
    if(cateringIteration == NULL) {
        cout << "Data catering kosong!" << endl;
    } else {
        while(cateringIteration != NULL) {
            cout << "ID : " << info(cateringIteration).id << endl;
            cout << "Nama : " << info(cateringIteration).name << endl;
            cout << "Harga : " << info(cateringIteration).price << endl;
            
            cout << "Menu : " << endl;
            if(firstChild(cateringIteration) == NULL) {
                cout << "Tidak ada menu" << endl;
            } else {
                showFoodMenuInRelation(firstChild(cateringIteration));
            }
        }
        
        cout << "============================" << endl;
    }
}
    
void showFoodMenuInRelation(RelationAddress relation) {
    while(relation != NULL) {
        cout << info(foodMenu(relation)).id <<  ") " << info(foodMenu(relation)).name << "[" << info(foodMenu(relation)).totalOrdered << "]" << endl;
        relation = next(relation);
    }
}
    
FoodMenuAddress showHightesOrdered(FoodMenuList list) { // Soal studi kasus
    if(first(list) == NULL) {
        return NULL;
    }
    
    FoodMenuAddress max = first(list);
    FoodMenuAddress iteration = first(list);
    while(iteration != NULL) {
        if(info(iteration).totalOrdered > info(max).totalOrdered) {
            max = iteration;
        }
        iteration = next(iteration);
    }
    
    return max;
}
