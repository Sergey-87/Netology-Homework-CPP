create table if not exists Executor (
	id serial primary key,
	Nickname text not null
);
create table if not exists The_genre_of_the_performer (
	id serial primary key,
	executor_id integer not null references Executor(id),
	genre_id integer not null references Genre(id)
);
create table if not exists Genre (
	id serial primary key,
	The_name_of_the_genre text not null
);
create table if not exists Album (
	id serial primary key,
	Album_Title text not null
);
create table if not exists Collection (
	id serial primary key,
	Title text not null,
	 Year_of_release integer not null
);
create table if not exists artists_album (
	id serial primary key,
	executor_id integer not null references Executor(id),
	album_id integer not null references Album(id)
);
create table if not exists Track (
	id serial primary key,
	album_id integer not null references Album(id),
	Title text not null,
	Duration integer not null
);
create table if not exists Collection_of_compositions (
	id serial primary key,
	collection_id integer not null references Collection(id),
	track_id integer not null references Track(id)
);