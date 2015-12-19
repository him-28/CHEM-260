struct point3d {
float x, y, z;
}; /* Note semicolon needed here */
int main(void) {
int i;
float x,y,z;
struct point3d point;
struct point3d points[2];
for (i=0; i<2; i++) {
scanf("%f %f %f", &x, &y, &z);
points[i].x=x;
points[i].y=y;
points[i].z=z;
}
point.x=points[1].x-points[0].x;
point.y=points[1].y-points[0].y;
point.z=points[1].z-points[0].z;
printf("dx=%7.3f dy=%7.3f dz=%7.3f\n",point.x,point.y,point.z);
}
