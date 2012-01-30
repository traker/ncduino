/*
 * table.h
 *
 *  Created on: 26 janv. 2012
 *      Author: guill
 */

#ifndef TABLE_H_
#define TABLE_H_

class Table{
private:
  double x_pos, x, x_target;
  double y_pos, y, y_target;
  double z_pos, z, z_target;
public:
    double getPos() const;
    void setPos(double x_pos);

};
#endif /* TABLE_H_ */
