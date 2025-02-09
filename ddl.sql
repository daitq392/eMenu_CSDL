CREATE TABLE categories (
  category_id INT,
  category_name VARCHAR(100),
  PRIMARY KEY (category_id)
);

CREATE TABLE dishes (
  dish_id INT,
  dish_name VARCHAR(100),
  price INT,
  category_id INT,
  unavailable_start_time TIME,
  unavailable_end_time TIME,
  PRIMARY KEY (dish_id),
  FOREIGN KEY (category_id) REFERENCES categories(category_id)
);

CREATE TABLE ingredients (
  ingredient_id INT,
  ingredient_name VARCHAR(100),
  quantity DECIMAL(6, 2),
  import_date DATE,
  expiration_date DATE,
  counting_unit VARCHAR(20),
  PRIMARY KEY (ingredient_id)
);

CREATE TABLE dish_ingredients (
  dish_id INT,
  ingredient_id INT,
  FOREIGN KEY (dish_id) REFERENCES dishes(dish_id),
  FOREIGN KEY (ingredient_id) REFERENCES ingredients(ingredient_id)
);

CREATE TABLE origins (
  origin_id INT,
  origin_name VARCHAR(50),
  PRIMARY KEY (origin_id)
);

CREATE TABLE dish_origins (
  dish_id INT,
  origin_id INT,
  FOREIGN KEY (dish_id) REFERENCES dishes(dish_id),
  FOREIGN KEY (origin_id) REFERENCES origins(origin_id)
);

