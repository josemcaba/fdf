// Esta función devuelve una estructura con las coordenadas (x,y) de cada uno de los puntos del segmento de la recta que une dos puntos en el plano.
// Los parámetros de entrada son las coordenadas de los dos puntos.
// Las coordenadas siempre serán números enteros.
// Las coordenadas de los puntos de la recta también serán números enteros.

struct point {
  int x;
  int y;
};

struct point *get_segment_points(int x1, int y1, int x2, int y2) {
  // Calcula la pendiente de la recta.
  int slope = (y2 - y1) / (x2 - x1);

  // Calcula la intersección de la recta con los ejes x e y.
  int x_intercept = x1 - (y1 * slope);
  int y_intercept = y1 * (x2 - x1) + y2;

  // Crea un array para almacenar los puntos del segmento.
  struct point *points = malloc(sizeof(struct point) * (x2 - x1 + 1));

  // Añade los puntos del segmento al array.
  for (int i = x1; i <= x2; i++) {
    points[i - x1].x = i * slope + y_intercept;
    points[i - x1].y = y_intercept;
  }

  // Devuelve el array de puntos.
  return points;
}
