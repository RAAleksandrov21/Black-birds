import React from "react";
import {
  StyleSheet,
  StatusBar,
  Platform,
  TextInput,
  Text,
  View,
  FlatList
} from "react-native";
import {Card, FAB} from "react-native-paper"

function Home({navigation}) {
  const data = [
    { id: 1, title: "First title", body: "First body" },
    { id: 2, title: "Second title", body: "First body" },
    { id: 3, title: "Third title", body: "First body" },
  ];

  const renderData = (item) =>{
    return (
      <Card style={styles.cardStyle}>
        <Text style={styles.infoCards}>{item.title}</Text>
        <Text style={styles.infoCards}>{item.body}</Text>
      </Card>
    );
  }
  return (
    <View style={styles.container}>
      <FlatList
        data={data}
        renderItem={({ item }) => {
          return renderData(item);
        }}
        keyExtractor={(item) => `${item.id}`}
      />
      <FAB
        style={styles.fab}
        small={false}
        icon={"plus"}
        onPress={() => {navigation.navigate("Create")}}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    alignItems: "center",
  },
  cardStyle:{
    margin:10,
    padding:10,
    width: 300,
    marginBottom:10
  },
  infoCards:{
    fontSize:20,
  },
  fab:{
    

  }
});

export default Home;
