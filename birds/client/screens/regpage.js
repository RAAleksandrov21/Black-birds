import React from "react";
import {
  ImageBackground,
  SafeAreaView,
  StyleSheet,
  View,
  Text,
  Image,
  Platform,
  StatusBar,
  Button,
} from "react-native";

function Regpage() {
  return (
    <View style={styles.boxInfo}>
      <Button title="Here is reg page" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
  },
  boxInfo: {
    backgroundColor: "dodgerblue",
    height: "30%",
    width: "100%",
    alignItems: "center",
    justifyContent: "center",
    flex: 0,
  },
  info: {
    color: "white",
    fontSize: 30,
  },
});

export default Regpage;
