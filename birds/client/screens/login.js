import React, { useState } from "react";
import {
  Platform,
  StyleSheet,
  Text,
  View,
  StatusBar,
  SafeAreaView,
} from "react-native";

const Login = () => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.boxInfo}>
        <Text>LogIn</Text>
      </View>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "black",
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

});

export default Login;
