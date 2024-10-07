CREATE TABLE IF NOT EXISTS Executor (
	id serial PRIMARY KEY,
	Nickname text NOT NULL
);
CREATE TABLE IF NOT EXISTS Genre (
	id serial PRIMARY KEY,
	The_name_of_the_genre text NOT NULL
);
CREATE TABLE IF NOT EXISTS The_genre_of_the_performer (
	id serial PRIMARY KEY,
	executor_id integer NOT NULL REFERENCES Executor(id),
	genre_id integer NOT NULL REFERENCES Genre(id)
);
CREATE TABLE IF NOT EXISTS Album (
	id serial PRIMARY KEY,
	Album_Title text NOT NULL
);
CREATE TABLE IF NOT EXISTS Collection (
	id serial PRIMARY KEY,
	Title text NOT NULL,
	 Year_of_release integer NOT NULL
);
CREATE TABLE IF NOT EXISTS artists_album (
	id serial PRIMARY KEY,
	executor_id integer NOT NULL REFERENCES Executor(id),
	album_id integer NOT NULL REFERENCES Album(id)
);
CREATE TABLE IF NOT EXISTS Track (
	id serial PRIMARY KEY,
	album_id integer NOT NULL REFERENCES Album(id),
	Title text NOT NULL,
	Duration integer NOT NULL
);
CREATE TABLE IF NOT EXISTS Collection_of_compositions (
	id serial PRIMARY KEY,
	collection_id integer NOT NULL REFERENCES Collection(id),
	track_id integer NOT NULL REFERENCES Track(id)
);