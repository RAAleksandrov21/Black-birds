import React from "react";
import {
  SafeAreaView,
  StyleSheet,
  StatusBar,
  Platform,
  TextInput,
  Text
} from "react-native";

function Home() {
  return (
    <SafeAreaView style={styles.container}>
      <Text>Home</Text>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    alignItems: "center",
  },
  input: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "50%",
    borderColor: "white",
  },
});

export default Home;
