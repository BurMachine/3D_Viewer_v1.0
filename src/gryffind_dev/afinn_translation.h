//
// Created by Gryffindor Dodie on 7/24/22.
//

#ifndef GRYFFIND_DEV_AFINN_TRANSLATION_H
#define GRYFFIND_DEV_AFINN_TRANSLATION_H

#include "parsing.h"

void change_of_size(Data *obj, double coefficient);

void change_of_size_x(Data *obj, double coefficient);
void change_of_size_y(Data *obj, double coefficient);
void change_of_size_z(Data *obj, double coefficient);

void move_x(Data *obj, double constant);
void move_y(Data *obj, double constant);
void move_z(Data *obj, double constant);

void turn_x(Data *obj, double corner);
void turn_y(Data *obj, double corner);
void turn_z(Data *obj, double corner);

#endif //GRYFFIND_DEV_AFINN_TRANSLATION_H
